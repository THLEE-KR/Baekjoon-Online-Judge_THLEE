#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool check_bfs[1010];
bool check_dfs[1010];

using namespace std;

vector<int> ad_list[1010];

void dfs(int node){
    cout << node << " ";
    check_dfs[node] = true;
    for(int i=0; i<ad_list[node].size(); i++){
        int y = ad_list[node][i];
        if(check_dfs[y] == false)
            dfs(y);
    }
}

void bfs(int node){
    check_bfs[node] = true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int i=0; i<ad_list[x].size(); i++){
            int next = ad_list[x][i];
            if(check_bfs[next] == false){
                check_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        ad_list[from].push_back(to);
        ad_list[to].push_back(from);
    }

    for(int i=1; i<=n; i++){
        sort(ad_list[i].begin(), ad_list[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
    cout << '\n';

    return 0;
}
