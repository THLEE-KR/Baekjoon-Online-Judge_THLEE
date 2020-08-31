#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int data[30][30];
int check[30][30];

int goA[] = {1,-1,0,0};
int goB[] = {0,0,1,-1};
int n;
vector<int> ansVec;
int ans;

int dfs(int i, int j){
    ans++;
    for(int k=0; k<4; k++){
        int ni = goA[k] + i;
        int nj = goB[k] + j;
        if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
        if(check[ni][nj] == false && data[ni][nj] == 1){
            check[ni][nj] = true;
            dfs(ni, nj);
        }
    }
    return ans;
}

int bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i, j));

    while(!q.empty()){
        int nowi = q.front().first;
        int nowj = q.front().second;
        ans++;
        q.pop();
        for(int k=0; k<4; k++){
            int ni = nowi + goA[k];
            int nj = nowj + goB[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            if(check[ni][nj] == false && data[ni][nj] == 1){
                check[ni][nj] = true;
                q.push(make_pair(ni, nj));
            }
        }
    }

    return ans;
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &data[i][j]);
        }
    }

//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            cout << data[i][j] << '\t';
//        }
//        cout << '\n';
//    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == false && data[i][j] == 1){
                check[i][j] = true;
                cnt++;
                ans = 0;
//                ansVec.push_back(dfs(i,j));
                ansVec.push_back(bfs(i,j));
            }
        }
    }
    sort(ansVec.begin(), ansVec.end());

    cout << cnt << '\n';
    for(int i=0; i<cnt; i++){
        cout << ansVec[i] << '\n';
    }

    return 0;
}
