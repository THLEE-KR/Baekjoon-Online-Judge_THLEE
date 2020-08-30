#include <iostream>
#include <vector>
using namespace std;
bool a[2010][2010];             // 인접 행렬
vector<int> g[2000];            // 인접 리스트
vector<pair<int,int>> edges;    // 간선 리스트
int main() {
    int N, M;
    cin >> N >> M; // 5 4

    for(int i=0; i<M; i++){
        int from, to;
        cin >> from >> to;
        edges.push_back({from, to});
        edges.push_back({to, from});
        a[from][to] = a[to][from] = true;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    M *= 2;
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            // A -> B
            int A = edges[i].first;
            int B = edges[i].second;
            // C -> D
            int C = edges[j].first;
            int D = edges[j].second;
            if(A == B || A == C || A == D || B == C || B == D || C == D) continue;

            // B -> C
            if(!a[B][C]) continue;

            // D -> E
            for(int E : g[D]){
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
