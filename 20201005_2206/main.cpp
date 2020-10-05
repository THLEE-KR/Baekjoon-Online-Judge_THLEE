#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int map[1000][1000];
int check[1000][1000][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(const int sa, const int sb, int broke){
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(sa, sb, broke));
    check[sa][sb][broke] = 1;

    while(q.empty() == false){
        int now_a, now_b, now_broke;
        tie(now_a, now_b, now_broke) = q.front();
        q.pop();

        for(int k=0; k<4; k++){
            int new_a = now_a + dx[k];
            int new_b = now_b + dy[k];
            if(new_a < 0 || new_a >= m || new_b < 0 || new_b >= n) continue;
            if(map[new_a][new_b] == 0 && check[new_a][new_b][now_broke] == 0){
                q.push(make_tuple(new_a, new_b, now_broke));
                check[new_a][new_b][now_broke] = check[now_a][now_b][now_broke] + 1;
            }
            if(map[new_a][new_b] == 1 && now_broke == 0 && check[new_a][new_b][now_broke+1] == 0){
                q.push(make_tuple(new_a, new_b, now_broke + 1));
                check[new_a][new_b][now_broke+1] = check[now_a][now_b][now_broke] + 1;
            }
        }
    }

    if(check[m-1][n-1][0] != 0 && check[m-1][n-1][1] != 0){
        cout << min(check[m-1][n-1][0], check[m-1][n-1][1]);
    }
    else if(check[m-1][n-1][0] != 0){
        cout << check[m-1][n-1][0];
    }
    else if(check[m-1][n-1][1] != 0){
        cout << check[m-1][n-1][1];
    }
    else{
        cout << -1;
    }

    cout << '\n';
    return;
}

int main() {
    cin >> m >> n;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

//    debugging
//    for(int i=0; i<m; i++){
//        for(int j=0; j<n; j++){
//            cout << map[i][j] << " ";
//        }
//        cout << '\n';
//    }
    int broke = 0;
    bfs(0, 0, broke);

//    debugging
//    for(int i=0; i<m; i++){
//        for(int j=0; j<n; j++){
//            cout << check[i][j][0] << "\t";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//    for(int i=0; i<m; i++){
//        for(int j=0; j<n; j++){
//            cout << check[i][j][1] << "\t";
//        }
//        cout << '\n';
//    }

    return 0;
}
