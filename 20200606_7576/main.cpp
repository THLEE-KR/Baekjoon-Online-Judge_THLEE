#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int map[1010][1010];
int cnt[1010][1010];
int goA[] = {1,-1,0,0};
int goB[] = {0,0,1,-1};
queue<pair<int,int>> q;

void bfs(void){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + goA[k];
            int ny = y + goB[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(map[nx][ny] == -1){
                cnt[nx][ny] = -1;
                continue;
            }
            if(cnt[nx][ny] == 0){
                q.push(make_pair(nx,ny));
                cnt[nx][ny] = cnt[x][y] + 1;
            }
//            cout << "nx: " << nx << " ny: " << ny << '\n';
//            cout << "cnt[nx][ny] : " << cnt[nx][ny] << '\n';
        }
    }
}

int main() {
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && cnt[i][j] == 0){
                q.push(make_pair(i,j));
                cnt[i][j] = 1;
            }
        }
    }

    bfs();

//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << cnt[i][j] << "\t";
//        }
//        cout << '\n';
//    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == -1)
                cnt[i][j] = -1;
        }
    }

    int ans = -999;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(cnt[i][j] == 0){
                cout << "-1" << '\n';
                return 0;
            }
            if(cnt[i][j] > ans)
                ans = cnt[i][j];
        }
    }

    if(ans == 1)
        cout << "0" << '\n';
    else
        cout << ans-1 << '\n';

    return 0;
}
