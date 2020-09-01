#include <iostream>
#include <queue>
using namespace std;
int data[1010][1010];
int goA[] = {1,-1,0,0};
int goB[] = {0,0,1,-1};
int m, n;

int check(){
    int maxVal = -1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(data[i][j] == 0)
                return -1;
            if(data[i][j] > maxVal)
                maxVal = data[i][j];
        }
    }

    return maxVal-1;
}

int bfs(){
    queue<pair<int, int>> q;

    for(int i=1; i<=m; i++) {
        for (int j = 1; j <= n; j++) {
            if (data[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }

    while(!q.empty()){
        int nowm = q.front().first;
        int nown = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int newm = nowm + goA[k];
            int newn = nown + goB[k];
            if(newm <= 0 || newm > m || newn <= 0 || newn > n) continue;
            if(data[newm][newn] == 0){
                q.push(make_pair(newm, newn));
                data[newm][newn] = data[nowm][nown] + 1;
            }
        }
    }

//    for(int i=1; i<=m; i++){
//        for(int j=1; j<=n; j++){
//            cout << data[i][j] << '\t';
//        }
//        cout << '\n';
//    }

    return check();
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> data[i][j];
        }
    }

//    for(int i=1; i<=m; i++){
//        for(int j=1; j<=n; j++){
//            cout << data[i][j] << '\t';
//        }
//        cout << '\n';
//    }
//    cout << '\n';

    cout << bfs() << '\n';


    return 0;
}
