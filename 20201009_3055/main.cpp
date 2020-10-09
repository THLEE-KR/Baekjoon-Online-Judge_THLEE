#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int water[50][50];
int d[50][50];

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for(int i=0; i<n; i++){
        cin >> map[i];
    }
    memset(water, -1, sizeof(water));
    queue<pair<int,int>> q;
    int sx,sy,ex,ey;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'D'){
                ex = i; ey = j;
            }
            else if(map[i][j] == 'S'){
                sx = i; sy = j;
            }
            else if(map[i][j] == '*'){
                q.push(make_pair(i,j));
                water[i][j] = 0;
            }
        }
    }

    while(q.empty() == false){
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(water[nx][ny] != -1) continue;
            if(map[nx][ny] == 'X' || map[nx][ny] == 'D') continue;
            water[nx][ny] = water[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }

    memset(d, -1, sizeof(d));
    q.push(make_pair(sx, sy));
    d[sx][sy] = 0;
    while(q.empty() == false){
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny > m) continue;
            if(d[nx][ny] != -1) continue;
            if(map[nx][ny] == 'X') continue;
            if(water[nx][ny] != -1 && d[x][y]+1 >= water[nx][ny]) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    if(d[ex][ey] == -1)
        cout << "KAKTUS\n";
    else
        cout << d[ex][ey] << '\n';

    return 0;
}
