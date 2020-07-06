#include <iostream>
#include <deque>
#include <tuple>
#include <cstring>
#define MAX 555

using namespace std;
int data[MAX][MAX];
int check[MAX][MAX];

int goA[] = {-1, 1, 0, 0};
int goB[] = {0, 0, 1, -1};

int BFS(int m, int n){
    deque<pair<int,int>> q;
    q.push_back(make_pair(1,1));
    memset(check, -1, sizeof(check));
    check[1][1] = 0;

    while(!q.empty()){
        int x, y;
        tie(x,y) = q.front();
        q.pop_front();

        for(int i=0; i<4; i++){
            int nx = x + goA[i];
            int ny = y + goB[i];
            if(nx<=0 || nx > n || ny <=0 || ny > m)
                continue;
            if(check[nx][ny] == -1){
                if(data[nx][ny] == 0) {
                    q.push_front(make_pair(nx,ny));
                    check[nx][ny] = check[x][y];
                }
                else {
                    q.push_back(make_pair(nx, ny));
                    check[nx][ny] = check[x][y] + 1;
                }
            }
        }
    }

    return check[n][m];
}


int main() {
    int m,n;
    cin >> m >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &data[i][j]);
        }
    }

    int ans = BFS(m,n);
    cout << ans << '\n';

    return 0;
}
