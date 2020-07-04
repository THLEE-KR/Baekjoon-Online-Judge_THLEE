#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int d[1010][1010];

void Solve(int input){
    memset(d, -1, sizeof(d));
    d[1][0] = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(1,0)); // value=1, clip=0
    while(!q.empty())
    {
        int s = q.front().first;
        int c = q.front().second;
        q.pop();

        // 복사
        if(d[s][s] == -1){
            d[s][s] = d[s][c]+1;
            q.push(make_pair(s,s));
        }
        // 붙여넣기
        if(s+c <= 1000 && d[s+c][c] == -1){
            d[s+c][c] = d[s][c]+1;
            q.push(make_pair(s+c,c));
        }
        // 삭제
        if(s-1 >= 0 && d[s-1][c] == -1){
            d[s-1][c] = d[s][c]+1;
            q.push(make_pair(s-1,c));
        }
    }
}

int main() {
    int input;
    cin >> input;

    Solve(input);

    int ans = 2000;
    for(int i=0; i<=input; i++){
        if(d[input][i] == -1) continue;
        if(ans > d[input][i])
            ans = d[input][i];
    }
    cout << ans << '\n';

    return 0;
}
