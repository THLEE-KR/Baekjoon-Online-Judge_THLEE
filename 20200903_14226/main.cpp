#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1000
int check[1010][1010];

int bfs(int start, int end){
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    memset(check, -1, sizeof(check));
    check[1][0] = 0;

    while(!q.empty()){
        int now = q.front().first;
        int save = q.front().second;
        q.pop();

        if(check[now][now] == -1){
            q.push(make_pair(now, now));
            check[now][now] = check[now][save] + 1;
        }

        if(now + save <= end && check[now+save][save] == -1){
            q.push(make_pair(now + save, save));
            check[now + save][save] = check[now][save] + 1;
        }

        if(now - 1 >= 0 && check[now-1][save] == -1){
            q.push(make_pair(now-1, save));
            check[now-1][save] = check[now][save] + 1;
        }
    }

    int ans = -1;
    for(int i=0; i<=end; i++){
        if(check[end][i] != -1){
            if(ans == -1 || ans > check[end][i])
                ans = check[end][i];
        }
    }
    cout << ans << '\n';

    return 0;
}

int main() {
    int n;
    cin >> n;

    bfs(1, n);

    return 0;
}
