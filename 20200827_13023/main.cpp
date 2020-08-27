#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool d[2010][2010];
vector<int> g[2010];
vector<pair<int, int>> edges;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
        edges.push_back({b,a});
        d[a][b] = d[b][a] = true;
        g[b].push_back(a);
        g[a].push_back(b);
    }
    m *= 2;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            int A = edges[i].first;
            int B = edges[i].second;

            int C = edges[j].first;
            int D = edges[j].second;

            if(A == B || A == C || A == D ||
            B == C || B == D || C == D)
                continue;

            if(!d[B][C])
                continue;

            for(int E: g[D]){
                if(A == E || B == E || C == E || D == E)
                    continue;
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';

    return 0;
}
