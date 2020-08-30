#include <iostream>
#include <vector>

using namespace std;
vector<int> v[1010];
bool check[1010];
int cnt;

void dfs(int start){
    for(int i=0; i<v[start].size(); i++){
        int next = v[start][i];
        if(check[next] == false){
            check[next] = true;
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    for(int i=1; i<=n; i++){
        if(check[i] == false){
            check[i] = true;
            cnt++;
            dfs(i);
        }

    }

    cout << cnt << '\n';

    return 0;
}
