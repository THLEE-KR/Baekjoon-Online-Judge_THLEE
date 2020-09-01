#include <iostream>
#include <queue>

using namespace std;
int data[110][110];
int goA[] = {1, -1, 0, 0};
int goB[] = {0, 0, 1, -1};
int m, n;

int bfs(int sm, int sn){
    queue<pair<int,int>> q;
    q.push(make_pair(sm, sn));
    data[sm][sn] += 1000;

    while(!q.empty()){
        int nowm = q.front().first;
        int nown = q.front().second;
//        cout << "nowm: " << nowm << " nown: " << nown << '\n';
        q.pop();

        for(int k=0; k<4; k++){
            int nextm = nowm + goA[k];
            int nextn = nown + goB[k];
            if(nextn < 0 || nextn >= n || nextm < 0 || nextm >= m) continue;
            if(data[nextm][nextn] == 1){
                q.push(make_pair(nextm, nextn));
                data[nextm][nextn] = data[nowm][nown] + 1;
            }
        }
    }

//    for(int i=0; i<m; i++){
//        for(int j=0; j<n; j++){
//            cout << data[i][j] << '\t';
//        }
//        cout << '\n';
//    }

    return data[m-1][n-1]-1000;
}

int main() {
    cin >> m >> n;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &data[i][j]);
        }
    }

//    for(int i=0; i<m; i++){
//        for(int j=0; j<n; j++){
//            cout << data[i][j] << '\t';
//        }
//        cout << '\n';
//    }

    cout << bfs(0, 0) << '\n';

    return 0;
}
