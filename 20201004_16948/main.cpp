#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int goA[] = {-2, -2, 0, 0, 2, 2};
int goB[] = {-1, 1, -2, 2, -1, 1};
int dist[210][210];

int bfs(const int r1, const int c1,
        const int r2, const int c2, const int n){
    queue<pair<int, int>> q;
    q.push(make_pair(r1, c1));
    dist[r1][c1] = 0;

    while(q.empty() == false){
        int now_r = q.front().first;
        int now_c = q.front().second;
        q.pop();
//        cout << "now_r: " << now_r << " now_c: " << now_c << " cnt: " << cnt << '\n';
        if(now_r == r2 && now_c == c2)
            return dist[now_r][now_c];

        for(int i=0; i<6; i++){
            int next_r = now_r + goA[i];
            int next_c = now_c + goB[i];
            if(next_r < 0 || next_r > n || next_c < 0 || next_c > n) continue;
            if(dist[next_r][next_c] == -1){
                q.push(make_pair(next_r, next_c));
                dist[next_r][next_c] = dist[now_r][now_c] + 1;
            }
        }
    }

    return -1;
}


int main() {
    int n;
    cin >> n;

    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(dist, -1, sizeof(dist));

    cout << bfs(r1, c1, r2, c2, n) << '\n';

    return 0;
}
