#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
tuple<int,int,int> bfs(vector<vector<int>> &a, int x, int y, int size){
    int n = a.size();
    vector<tuple<int,int,int>> ans;
    vector<vector<int>> d(n, vector<int> (n, -1));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = 0;

    while(q.empty() == false){
        tie(x,y) = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(d[nx][ny] != -1) continue;

            bool ok = false;
            bool eat = false;
            if(a[nx][ny] == 0){
                ok = true;
            }
            else if(a[nx][ny] < size){
                ok = eat = true;
            }
            else if(a[nx][ny] == size){
                ok = true;
            }
            if(ok){
                q.push(make_pair(nx, ny));
                d[nx][ny] = d[x][y] + 1;
                if(eat){
                    ans.push_back(make_tuple(d[nx][ny], nx, ny));
                }
            }
        }
    }
    if(ans.empty()){
        return make_tuple(-1, -1, -1);
    }
    sort(ans.begin(), ans.end());
    return ans[0];
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    int x, y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j] == 9){   // 상어의 위치
                tie(x,y) = make_pair(i, j);
                a[i][j] = 0;
            }
        }
    }
    int ans = 0;
    int size = 2;
    int exp = 0;

    while(true){
        int nx, ny, dist;
        tie(dist, nx, ny) = bfs(a, x, y, size);
        if(dist == -1) break; // 엄마상어 콜
        a[nx][ny] = 0;
        ans += dist;
        exp += 1; // 물고기 먹은 횟수
        if(size == exp){    // 자신의 크기만큼 먹으면 크기 증가
            size += 1;
            exp = 0;
        }
        tie(x,y) = make_pair(nx,ny);
    }
    cout << ans << '\n';

    return 0;
}
