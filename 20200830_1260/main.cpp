#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool a[1010][1010];      // 인접행렬
vector<int> b[1010];    // 인접리스트
vector<pair<int, int>> c;  // 간선리스트

int n, m, start;
bool check_dfs_a[1010];
bool check_bfs_a[1010];
bool check_dfs_b[1010];
bool check_bfs_b[1010];
bool check_dfs_c[1010];
bool check_bfs_c[1010];

void dfs_a(int start){
    cout << start << " ";
    check_dfs_a[start] = true;

    for(int i=1; i<=n; i++){
        if(check_dfs_a[i] == false && a[start][i] == true){
            dfs_a(i);
        }
    }
}
void bfs_a(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(check_bfs_a[now] == true) continue;
        check_bfs_a[now] = true;
        cout << now << " ";

        for(int i=1; i<=n; i++) {
            if (check_bfs_a[i] == false && a[now][i] == true){
//                cout << "i: " << i << '\n';
                q.push(i);
            }
        }
    }
}

void dfs_b(int start){
    cout << start << " ";
    check_dfs_b[start] = true;

    for(int i=0; i<b[start].size(); i++){
        if(check_dfs_b[b[start][i]] == false)
            dfs_b(b[start][i]);
    }
}
void bfs_b(int start){
    queue<int> q;
    q.push(start);
    check_bfs_b[start] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now << " ";

        for(int i=0; i<b[now].size(); i++) {
            if(check_bfs_b[b[now][i]] == false){
                check_bfs_b[b[now][i]] = true;
                q.push(b[now][i]);
            }
        }
    }
}

void dfs_c(int start){
    cout << start << " ";
    check_dfs_c[start] = true;

    for(int i=0; i<c.size(); i++){
        int first = c[i].first;
        int second = c[i].second;
        if(first != start) continue;

        if(check_dfs_c[second] == false){
            check_dfs_c[second] = true;
            dfs_c(second);
        }
    }
}
void bfs_c(int start){
    queue<int> q;
    q.push(start);
    check_bfs_c[start] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now << " ";

        for(int i=0; i<c.size(); i++) {
            int first = c[i].first;
            int second = c[i].second;
            if(first != now) continue;

            if(check_bfs_c[second] == false){
                check_bfs_c[second] = true;
                q.push(second);
            }
        }
    }
}

int main() {

    cin >> n >> m >> start;

    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        a[from][to] = a[to][from] = true;

        b[from].push_back(to);
        b[to].push_back(from);

        c.push_back({from, to});
        c.push_back({to, from});
    }

//    dfs_a(start);
//    cout << '\n';
//    bfs_a(start);
//    cout << '\n';

//    for(int i=1; i<=n; i++){
//        sort(b[i].begin(), b[i].end());
//    }
//    dfs_b(start);
//    cout << '\n';
//    bfs_b(start);
//    cout << '\n';

    sort(c.begin(), c.end());
    dfs_c(start);
    cout << '\n';
    bfs_c(start);
    cout << '\n';

    return 0;
}
