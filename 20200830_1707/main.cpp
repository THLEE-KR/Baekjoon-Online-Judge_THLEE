#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> data[20001];
int color[20001];

//bool dfs(int start, int c){
//    color[start] = c;
//    for(int i=0; i<data[start].size(); i++){
//        int next = data[start][i];
//        if(color[next] == 0){
//            if(dfs(next, 3-c) == false)
//                return false;
//        }
//        else if(color[next] == color[start])
//            return false;
//    }
//    return true;
//}
//
//int main() {
//    int k;
//    cin >> k;
//    while(k--){
//        int v, e;
//        cin >> v >> e;
//
//        for(int i=1; i<=v; i++){
//            data[i].clear();
//            color[i] = 0;
//        }
//
//        for(int i=0; i<e; i++){
//            int from, to;
//            cin >> from >> to;
//            data[from].push_back(to);
//            data[to].push_back(from);
//        }
//
//        bool ok = true;
//        for(int i=1; i<=v; i++){
//            if(color[i] == 0){
//                if(dfs(i, 1) == false){
//                    ok = false;
//                }
//            }
//        }
//        if(ok == true)
//            cout << "YES" << '\n';
//        else
//            cout << "NO" << '\n';
//    }
//
//    return 0;
//}

void dfs(int node, int c){
    color[node] = c;
    for(int i=0; i<data[node].size(); i++){
        int next = data[node][i];
        if(color[next] == 0){
            dfs(next, 3-c);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            data[i].clear();
            color[i] = 0;
        }
        for(int i=0; i<m; i++){
            int u,v;
            cin >> u >> v;
            data[u].push_back(v);
            data[v].push_back(u);
        }
        for(int i=1; i<=n; i++){
            if(color[i] == 0)
                dfs(i, 1);
        }
        bool ok = true;
        for(int i=1; i<=n; i++){
            for(int k=0; k<data[i].size(); k++){
                int j = data[i][k];
                if(color[i] == color[j])
                    ok = false;
            }
        }
        if(ok == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}
