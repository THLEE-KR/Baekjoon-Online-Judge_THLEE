#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

int goA[] = {1,1,1,0,0,-1,-1,-1};
int goB[] = {1,0,-1,1,-1,-1,0,1};
int data[55][55];
bool check[55][55];
int m,n;

void dfs(int i, int j){
    for(int k=0; k<8; k++){
        int ni = i + goA[k];
        int nj = j + goB[k];
        if(ni < 0 || ni >= m || nj < 0 || nj >=n) continue;
        if(check[ni][nj] == false && data[ni][nj] == 1){
            check[ni][nj] = true;
            dfs(ni, nj);
        }
    }
}

int main() {
    while(1){
        cin >> n >> m;
        if(m == 0 && n == 0) break;

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> data[i][j];
                check[i][j] = 0;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(check[i][j] == false && data[i][j] == 1){
                    cnt++;

                    check[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
