#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> a(n);
    int sx, sy, ex, ey;
    sx = sy = ex = ey = -1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        for(int j=0; j<m; j++){
            if(a[i][j] == 'C'){
                if(sx == -1){
                    sx = i;
                    sy = j;
                }
                else{
                    ex = i;
                    ey = j;
                }
            }
        }
    }
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    d[sx][sy] = 0;
    q.push(make_pair(sx,sy));
    while(q.empty() == false){
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            while(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(a[nx][ny] == '*') break;
                if(d[nx][ny] == -1){
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                nx += dx[k];
                ny += dy[k];
            }
        }
    }
    cout << d[ex][ey] -1 << '\n';
    return 0;
}