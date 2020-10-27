#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int check[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int n;
    cin >> n;
    vector<string> input(n);

    for(int i=0; i<n; i++){
        cin >> input[i];
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == 0){
                cnt++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                check[i][j] = cnt;
                char color = input[i][j];

                while(q.empty() == false){
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(check[nx][ny] != 0) continue;
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(input[nx][ny] == color){
                            check[nx][ny] = cnt;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
    cout << cnt << ' ';

    memset(check, 0, sizeof(check));
    cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == 0){
                cnt++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                check[i][j] = cnt;
                char color = input[i][j];

                while(q.empty() == false){
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(check[nx][ny] != 0) continue;
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(input[nx][ny] == 'B'){
                            if(color != 'B') continue;
                            check[nx][ny] = cnt;
                            q.push(make_pair(nx, ny));
                        }
                        else{
                            if(color == 'B') continue;
                            check[nx][ny] = cnt;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            cout << check[i][j] << " ";
//        }
//        cout << '\n';
//    }
    cout << cnt << '\n';


    return 0;
}
