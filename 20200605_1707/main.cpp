#include <iostream>
#include <vector>

using namespace std;

bool check[30000];
vector<int> data[30000];
int color[30000];

void dfs(int node, int c){
    color[node] = c;
//    cout << "node: " << node << " c: " << c << '\n';
    for(int i=0; i<data[node].size(); i++){
        int next = data[node][i];
        if(color[next] == 0)
            dfs(next, 3-c);
    }
}

int main() {
    int n;
    cin >> n;
    while(n--){
        int V, E;
        cin >> V >> E;

        for(int i=1; i<=V; i++){
            data[i].clear();
            color[i] = 0;
        }

        for(int i=0; i<E; i++){
            int a, b;
            cin >> a >> b;
            data[a].push_back(b);
            data[b].push_back(a);
        }

        for(int i=1; i<=V; i++){
            if(color[i] == 0)
                dfs(i, 1);
        }

        bool ok = true;
        for(int i=1; i<=V; i++){
            for(int k=0; k<data[i].size(); k++){
                int j = data[i][k];
                if(color[i] == color[j])
                    ok = false;
            }
        }
        if(ok)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}