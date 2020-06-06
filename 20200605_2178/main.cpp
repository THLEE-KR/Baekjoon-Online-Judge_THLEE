#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int map[110][110];
int check[110][110];
int n, m;

int goA[] = {1,-1,0,0};
int goB[] = {0,0,1,-1};

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    check[i][j] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
//        cout << x << " " << y << '\n';
        for(int k=0; k<4; k++){
            int nx = x + goA[k];
            int ny = y + goB[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(map[nx][ny] == 0)
                continue;
            if(check[nx][ny] != 0)
                continue;
            q.push(make_pair(nx,ny));
//            cout << "nx: " << nx << " ny: " << ny << " cnt: " << cnt << "\n";
            check[nx][ny] = check[x][y] + 1;
        }
    }
}

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            bfs(0, 0);
        }
    }
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << check[i][j] << '\t';
//        }
//        cout << '\n';
//    }

    cout << check[n-1][m-1] << '\n';

    return 0;
}
