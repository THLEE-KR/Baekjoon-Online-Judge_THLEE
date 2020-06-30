#include <iostream>
#include <queue>
using namespace std;

#define MAX 20000 + 10

bool check[MAX];
int dist[MAX];
int Solve(int n, int k){
    int t = 0;
    int ans;
    queue<int> q;
    check[n] = true;
    q.push(n);
    dist[n] = 0;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans = dist[now];

        if(now == k) break;

        int next[] = {now+1, now-1, now*2};
        for(int i=0; i<3; i++){
            if(check[next[i]] == true)
                continue;
            if(next[i] >= 0 && next[i] <= 100000){
                q.push(next[i]);
                dist[next[i]] = ans + 1;
                check[next[i]] = true;
            }
        }
    }
    return ans;
}

int main() {
    int n,k;
    cin >> n >> k;
    int ans = Solve(n, k);
    cout << ans << '\n';
    return 0;
}
