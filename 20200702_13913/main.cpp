#include <iostream>
#include <queue>
#include <stack>

const int MAX = 200000;

int from[MAX+1];
bool check[MAX+1];
int t[MAX+1];

using namespace std;
stack<int> s;

void bfs(int n, int k){
    t[n] = 0;
    queue<int> q;
    q.push(n);
    check[n] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        if(now-1>=0){
            if(check[now-1] == false){
                q.push(now-1);
                check[now-1] = true;
                t[now-1] = t[now] + 1;
                from[now-1] = now;
            }
        }
        if(now+1<MAX){
            if(check[now+1] == false){
                q.push(now+1);
                check[now+1] = true;
                t[now+1] = t[now] + 1;
                from[now+1] = now;
            }
        }
        if(now*2<MAX){
            if(check[now*2] == false){
                q.push(now*2);
                check[now*2] = true;
                t[now*2] = t[now] + 1;
                from[now*2] = now;
            }
        }
    }
    cout << t[k] << '\n';

    stack<int> ans;
    for(int i=k; i!=n; i=from[i]){
        ans.push(i);
    }
    ans.push(n);
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << '\n';
}

int main() {
    int n,k;
    cin >> n >> k;

    bfs(n, k);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}
