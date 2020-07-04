#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;

bool check[MAX + 10];
int d[MAX + 10];

void Solve(int now, int target){
    check[now] = true;
    d[now] = 0;
    queue<int> q, next_q;
    q.push(now);

    while(!q.empty()){
        int nnow = q.front();
        q.pop();
        if(nnow*2 < MAX){
            if(check[nnow*2] == false){
                q.push(nnow*2);
                check[nnow*2] = true;
                d[nnow*2] = d[nnow];
            }
        }
        if(nnow-1 >= 0){
            if(check[nnow-1] == false){
                next_q.push(nnow-1);
                check[nnow-1] = true;
                d[nnow-1] = d[nnow] + 1;
            }
        }
        if(nnow+11 < MAX){
            if(check[nnow+1] == false){
                next_q.push(nnow+1);
                check[nnow+1] = true;
                d[nnow+1] = d[nnow] + 1;
            }
        }
        if(q.empty()){
            q = next_q;
            next_q = queue<int>();
        }
    }
}

int main() {
    int now, target;
    cin >> now >> target;

    Solve(now, target);
    cout << d[target];
    return 0;
}
