#include <iostream>
#include <queue>
using namespace std;
int m,n;
int map[10][10];
int map2[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(){
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            map2[i][j] = map[i][j];
            if(map2[i][j] == 2){
                q.push(make_pair(i,j));
            }
        }
    }
    while(q.empty() == false){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map2[nx][ny] == 0){
                map2[nx][ny] = 2;
                q.push(make_pair(nx,ny));
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map2[i][j] == 0)
                cnt ++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    int ans = 0;
    for(int x1 = 0; x1 < n; x1++){
        for(int y1 = 0; y1 < m; y1++){
            if(map[x1][y1] != 0) continue;
            for(int x2 = 0; x2 < n; x2++){
                for(int y2 = 0; y2 < m; y2++){
                    if(map[x2][y2] != 0) continue;
                    for(int x3 = 0; x3 < n; x3++){
                        for(int y3 = 0; y3 < m; y3++){
                            if(map[x3][y3] != 0) continue;
                            if(x1 == x2 && y1 == y2) continue;
                            if(x1 == x3 && y1 == y3) continue;
                            if(x2 == x3 && y2 == y3) continue;
                            map[x1][y1] = 1;
                            map[x2][y2] = 1;
                            map[x3][y3] = 1;
                            int cur = bfs();
                            if(ans < cur) ans = cur;
                            map[x1][y1] = 0;
                            map[x2][y2] = 0;
                            map[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
