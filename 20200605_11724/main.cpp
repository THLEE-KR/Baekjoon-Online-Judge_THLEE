#include <iostream>
#include <vector>

using namespace std;
bool check[1010];
vector<int> data[1010];

void dfs(int n){
    check[n] = true;
    for(int i=0; i<data[n].size(); i++){
        int next = data[n][i];
        if(!check[next])
            dfs(next);
    }
}

int main() {
    int n,m;
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int a,b;
        cin >> a >> b;

        data[a].push_back(b);
        data[b].push_back(a);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!check[i]){

            dfs(i);
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
