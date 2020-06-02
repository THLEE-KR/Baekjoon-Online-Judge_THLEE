#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 배열 초기화!!!
vector<pair<int, int>> edge_list;
bool ad_mat[2000][2000];
vector<int> ad_list[2000];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;

        edge_list.push_back({from, to});
        edge_list.push_back({to, from});
        ad_mat[from][to] = ad_mat[to][from] = true;
        ad_list[from].push_back(to);
        ad_list[to].push_back(from);
    }

    for(int i=0; i<2*m; i++){
        for(int j=0; j<2*m; j++){
            int A = edge_list[i].first;
            int B = edge_list[i].second;
            int C = edge_list[j].first;
            int D = edge_list[j].second;
            if(A == B || A == C || A == D || B == C || B == D || C == D)
                continue;
            if(!ad_mat[B][C])
                continue;
            for(int E : ad_list[D]){
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
