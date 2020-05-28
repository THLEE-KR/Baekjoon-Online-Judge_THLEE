#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INF 100000
#define N 1024

#define FREE -1


/*
    global variables
*/

int cost_mat[N][N];

int lx[N];              // label x  (계산값)
int ly[N];              // label y  (계산값)

int S[N];               // S 집합, 큐 자료구조, x점에 해당되는 (인덱스값)
int s_read, s_write;    // read는 dequeue를 위해, write는 enqueue를 위해

int T[N];               // T 집합, 존재하지 않으면 0의 값을, 존재하면 1의 값을 지닌다. (bool값)



// Matching graph
int x_y[N];             // x 점에서 매칭되는 y점을 나타낸다, (인덱스값)
int y_x[N];             // y 점에서 매칭되는 x점을 나타낸다, (인덱스값)



// O(n^4) 를 O(n^3)으로 줄이기 위해 사용하는 slack 관련
int slacky[N];          // 해당 y점이 지니는 가장 작은 delta 값을 나타낸다. (계산값)
int slack_x[N];         // 해당 y점에서 가장 작은 delta값으로 연결된 x점을 나타낸다. (인덱스값)


int cnt_match;          // 총 매칭된 수, 이것이 n과 같아지면 전부 매칭된 것이다.


/*
    print funcs
*/
void print_xy(int n){
    int i,j;
    for(i=0; i<n; i++){
        printf(" {");
        for(j=0; j<n; j++){
            if(x_y[i] == j)
                printf("%2d,", cost_mat[i][j]);
            else
                printf("  ,");
        }
        printf("}\n");
    }
    printf("\n");
}

void print_arr(char* str, int* arr, int n){
    int i;
    printf("%s = {", str);
    for(i=0; i<n; i++){
        printf("%d, ", arr[i]);
    }
    printf("}\n");
}



/*
    sub routines
*/


// 라벨링 초기화 : O(n^2)

void init_labels(int n){

    int i, j, index;

    // Matching graph 초기화
    memset(x_y, FREE, n * sizeof(int));
    memset(y_x, FREE, n * sizeof(int));

    for(i=0; i<n; i++){

        lx[i] = -1 * INF;

        // 각 열에서 max값을 찾아 라벨링, 인덱스를 알아낸다.
        for(j=0; j<n; j++){

            if(lx[i] < cost_mat[i][j]){

                lx[i] = cost_mat[i][j];
                index = j;
            }
        }

        // 초기 Matching graph 생성
        if(y_x[index] == FREE){
            x_y[i] = index;
            y_x[index] = i;

            cnt_match++;
        }
        /*
            매칭 그래프에서 y가 이미 점을 가지고 있으면 (FREE하지 않으면)
            기존에 연결된 것이므로 alternating tree가 반드시 존재한다.
        */

    }

}


// M graph가 perfect인지 판별 : O(1)

int is_perfect(int n){

    if( cnt_match < n)
        return 0;
    else
        return 1;
}


// S집합과 T집합을 초기화 : O(n)

void init_S_T(int n){
    int i;

    // S 집합은 큐이므로 ,read지점과 write지점만 초기화
    s_read = s_write = 0;

    // T 집합은 bool값을 지니므로 0으로 초기화
    memset(T, 0, n * sizeof(int));

    for(i=0; i<n; i++){

        if(x_y[i] == FREE){

            S[s_write++] = i; // free한 x 점 하나를 선택하여 S집합에 추가한다.
            break;
        }
    }
}



/*
    for slack
*/

// 주어진 x 점에서 계산되는 T집합에 포함되지 않는 y와 연결되는
// 모든 간선비용(delta)에 대하여 기존 slack y값과 비교하여
// 더 작은 값이면 업데이트 하고 그 x 점을 기록한다. : O(n)

void slack_update(int x, int n){
    int i, delta;

    for(i=0; i<n; i++){

        delta = lx[x] + ly[i] - cost_mat[x][i];

        if(!T[i] && slacky[i] > delta){

            slacky[i] = delta;
            slack_x[i] = x;
        }
    }
}



// T 집합에 포함되지 않는 y점중 slack에서 가장 작은 값을 찾아
// 인덱스를 반환한다. : O(n)

int find_in_slack(int n){
    int i;
    int min = INF;
    int index = FREE;

    for(i=0; i<n; i++){
        if(!T[i] && slacky[i] >=0 && min > slacky[i]){
            min = slacky[i];
            index = i;
        }
    }
    return index;
}

// 라벨 업데이트 및 slack y값 조정 : 3 * O(n)

void update_labels(int delta, int n){

    int i;

    // S 집합에 속하는 x의 라벨 업데이트
    for(i=0; i<n; i++){
        if(S[i]){
            lx[i] -= delta;
        }
    }
    // T 집합에 속하는 y의 라벨 업데이트
    for(i=0; i<n; i++){
        if(T[i]){
            ly[i] += delta;
        }
    }

    // slacky 에다가도 delta 값을 빼주는 이유는
    // T집합에 속하지 않는 y들에 대해 slacky는 어차피
    // 최소비용 후보들이기 때문에 label x 가 delta만큼
    // 줄어들어 차이가 생긴다. 이것을 Equality 속성이
    // 만족하게 보정한다.
    // 바로 직전에 선택한 간선의 slacky 값은 0이 될 것이다. (직후에 T집합에 포함된다)
    for(i=0; i<n; i++){
        if(!T[i]){
            slacky[i] -= delta;
        }
    }
}


// matching graph 재 생성 : O(n) , tail recursion

void reconstruct_matching_graph(int x, int y, int n){
    int tmp;

    if(x_y[x] != FREE){
        tmp = x_y[x];
        x_y[x] = y;
        y_x[y] = x;

        reconstruct_matching_graph( slack_x[tmp], tmp, n);
    }else{
        x_y[x] = y;
        y_x[y] = x;
    }
}



// augmenting path를 찾아 추가하는 과정 (핵심) : O(n^2)

void augment(int n){
    int x, y;
    int i;

    // init slack
    for(i=0; i<n; i++) slacky[i] = INF;
    memset(slack_x, FREE, n * sizeof(int));

    // 모든 S 집합에 대하여 계산 : 큐 , 최악의 경우 n-1 만큼 반복된다.
    while(s_read < s_write){

        // S 집합에서 하나를 읽어와 slack 계산 : O(n)
        slack_update( S[s_read++], n);

        // slack에서 가장 작은 비용을 갖는 간선을 찾는다. : O(n)
        y = find_in_slack(n);
        x = slack_x[y];

        // 그 해당 y점이 free하면 augmenting path를 찾은 것이다!!
        if(y_x[y] == FREE){
            break;
        }

        // 라벨 재조정 한다.  : 3 x O(n)
        update_labels(slacky[y], n);

        // alternating tree 확장 : 해당 y점이 matched 이기 때문
        S[s_write++] = y_x[y]; // 기존에 매치된 y점과 연결되어 있는 x점을 S집합에 추가
        T[y] = 1;               // T집합에 y 추가
    }

    // 찾아낸 augmenting path를 기준으로 Matching graph 재조정 : O(n)
    reconstruct_matching_graph(x,y,n);
    cnt_match++;
}







/*
    main algorithm
*/


// 헝가리안 알고리즘 : O(n^3)

void hungarian(int n){

    // step 1
    init_labels(n);

    // step 2
    while(!is_perfect(n)){


        init_S_T(n); // O(n)

    // step 3,4
        augment(n); // O(n^2)

    }
}


//-------------------------------------------------------------

int main(void){
    int i,j;
    int sum=0;

    int cost[10][10] = {
        {4,6,9,4,3,9,7,1,7,2},
        {9,6,8,4,4,7,3,4,1,1},
        {1,3,3,1,7,3,8,5,9,2},
        {4,6,1,4,6,2,1,6,7,1},
        {3,6,6,1,4,2,8,1,7,2},
        {4,6,2,4,3,1,3,4,1,2},
        {1,9,8,4,4,2,8,2,6,2},
        {5,6,1,8,4,6,9,4,7,1},
        {1,6,8,4,6,9,6,1,1,2},
        {4,5,2,4,5,2,8,8,7,1}
    };
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            cost_mat[i][j] = cost[i][j];
        }
    }

    hungarian(10);

    print_xy(10);
    print_arr("x-y", x_y, 10);

    for(i=0; i<10; i++){
        sum += cost[i][x_y[i]];
    }
    printf("optimal: %d\n", sum);

    return 0;
}

//int main(void){
//
//    int i,j;
//    int cost[3][3] = {
//                        {7,4,3},    //,-5},
//                        {3,1,3},    //3,-8},
//                        {4,0,0}     //-7,-6,-4,-5},
//                        // {-9,-10,-3,-8}
//    };
//    for(i=0; i<3; i++){
//        for(j=0; j<3; j++){
//            cost_mat[i][j] = cost[i][j];
//        }
//    }
//
//    hungarian(3);
//
//    print_xy(3);
//
//    print_arr("x-y", x_y, 3);
//
//    return 0;
//}