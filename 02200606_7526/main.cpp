#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int cnt[310][310];
int n, size;
int goA[] = {1, 2, 2, 1, -1, -2, -2, -1};
int goB[] = {2, 1, -1, -2, -2, -1, 1, 2};

vector<pair<int,int>> s;
vector<pair<int,int>> e;

void bfs(int x, int y){
    cnt[x][y] = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();a
        for(int k=0; k<8; k++){
            int nx = nowx + goA[k];
            int ny = nowy + goB[k];
            if(nx < 0 || nx >= size || ny < 0 || ny >= size)
                continue;
            if(cnt[nx][ny] != -1)
                continue;

            q.push(make_pair(nx,ny));
            cnt[nx][ny] = cnt[nowx][nowy] + 1;
//            cout << "nx : " << nx << " ny : " << ny << '\n';
        }
    }
}

int main() {
    cin >> n;
    while(n--){
        cin >> size;

        int a,b;
        cin >> a >> b;
        s.push_back(make_pair(a,b));
        cin >> a >> b;
        e.push_back(make_pair(a,b));

        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cnt[i][j] = -1;
            }
        }

        bfs(s[0].first, s[0].second);

        cout << cnt[e.front().first][e.front().second] << '\n';
        s.clear();
        e.clear();
    }

    return 0;
}
