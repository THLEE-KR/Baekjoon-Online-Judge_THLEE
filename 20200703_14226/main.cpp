#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int d[1001][1001];  // time, check 역할도 함

void Solve(int n){
    memset(d, -1, sizeof(d));
    queue<pair<int,int>> q;
    q.push(make_pair(1,0)); // value, copy
    d[1][0] = 0; // time at d[s][c];

    while(!q.empty()) {
        int s, c;
        tie(s, c) = q.front();
        q.pop();
        if (d[s][s] == -1) {  // d[1][1] == -1 -> d[1][0]+1=1
            d[s][s] = d[s][c] + 1;
            q.push(make_pair(s, s)); // copy
        }
        if (s + c <= 1000 && d[s + c][c] == -1) {
            d[s + c][c] = d[s][c] + 1;
            q.push(make_pair(s + c, c));  // paste
        }
        if (s - 1 >= 0 && d[s - 1][c] == -1) {    // delete
            d[s - 1][c] = d[s][c] + 1;
            q.push(make_pair(s - 1, c));
        }
    }
}

int main(){
    int n;
    cin >> n;

    Solve(n);

    int ans = -1;
    for(int i=0; i<=n; i++){
        if(d[n][i] != -1){
            if(ans == -1 || ans > d[n][i]){
                ans = d[n][i];
//                cout << "ans: " << ans << '\n';
            }
        }
    }
    cout << ans << '\n';
    return 0;
}