#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
int map[30][30];
bool check[30][30];
int gi[4] = {0, 1, 0, -1};
int gj[4] = {1, 0, -1, 0};
int ans[30*30];

void dfs(int i, int j, int size){
    check[i][j] = true;
    map[i][j] = cnt;

    for(int k=0; k<4; k++){
        int ni = i + gi[k];
        int nj = j + gj[k];
        if(ni < 0 || ni >= size || nj < 0 || nj >= size)
            continue;
        if(check[ni][nj])
            continue;
        if(map[ni][nj] == 0)
            continue;
        dfs(ni, nj, size);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == false && map[i][j] != 0){
                cnt++;
                dfs(i,j, n);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[map[i][j]] += 1;
        }
    }

    cout << cnt << '\n';
    sort(ans+1, ans+cnt+1);
    for(int i=1; i<=cnt; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}
