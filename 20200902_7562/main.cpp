#include <iostream>
#include <queue>

using namespace std;
int check[310][310];

int goA[] = {2, 1, -2, -1, 2, 1, -2, -1};
int goB[] = {1, 2, 1, 2, -1, -2, -1, -2};

int bfs(int sx, int sy, int ex, int ey, int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            check[i][j] = 0;
        }
    }

    if(sx == ex && sy == ey)
        return 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    check[sx][sy] = 1000;
    int cnt = 0;
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int nextx = nowx + goA[i];
            int nexty = nowy + goB[i];
            if(nextx < 0 || nextx >= len || nexty < 0 || nexty >= len) continue;
            if(check[nextx][nexty] == 0){
                check[nextx][nexty] = check[nowx][nowy] + 1;
                if(nextx == ex && nexty == ey){
                    return check[nextx][nexty]-1000;
                }
                q.push(make_pair(nextx, nexty));
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    while(n--){
        int sx, sy, ex, ey, len;
        cin >> len;
        cin >> sx >> sy;
        cin >> ex >> ey;
        cout << bfs(sx, sy, ex, ey, len) << '\n';
    }

    return 0;
}
