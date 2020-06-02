#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int from, to;
};
Edge edges[20010];

int cnt[1010];
bool check_bfs[1010];
bool check_dfs[1010];

bool cmp(const Edge &u, const Edge &v) {
    if(u.from == v.from)
        return u.to < v.to;
    else
        return u.from < v.from;
}

void dfs(int node){
    check_dfs[node] = true;
    cout << node << " ";
    for(int i=cnt[node-1]; i<cnt[node]; i++){
        int next = edges[i].to;
        if(check_dfs[next] == false)
            dfs(next);
    }
}

void bfs(int node){
    queue<int> q;
    q.push(node);
    check_bfs[node] = true;
    while(!q.empty()){
        int node2 = q.front();
        q.pop();
        cout << node2 << " ";
        for(int i=cnt[node2-1]; i<cnt[node2]; i++) {
            int next = edges[i].to;
            if (check_bfs[next] == false) {
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
        cin >> edges[i].from >> edges[i].to;
        edges[i+m].from = edges[i].to;
        edges[i+m].to = edges[i].from;
    }
    m *=2;
    sort(edges, edges+m, cmp);
    for(int i=0; i<m; i++){
        cnt[edges[i].from] += 1;
    }
    for(int i=1; i<=n; i++){
        cnt[i] += cnt[i-1];
    }

    dfs(v);
    cout << '\n';
    bfs(v);
    cout << '\n';

    return 0;
}
