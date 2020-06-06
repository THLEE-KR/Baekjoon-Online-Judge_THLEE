#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[55][55];
bool check[55][55];
int goA[] = {0,0,1,-1,1,1,-1,-1};
int goB[] = {1,-1,0,0,1,-1,1,-1};
int cnt = 0;
int w,h;

void bfs(int i, int j, int cnt){
    check[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i,j));

    while(!q.empty()){
        int nowi = q.front().first;
        int nowj = q.front().second;
        q.pop();

        for(int k=0; k<8; k++){
//            cout << "k : " << k << '\n';
            int ni = nowi + goA[k];
            int nj = nowj + goB[k];
//            cout << "ni " << ni << " nj " << nj << '\n';
            if(ni < 0 || ni >= h || nj < 0 || nj >= w)
                continue;
            if(map[ni][nj] == 0)
                continue;
            if(check[ni][nj] == true)
                continue;
            q.push(make_pair(ni,nj));
            check[ni][nj] = true;
//            cout << "ni : " << ni << " nj: " << nj << '\n';
        }
    }
}

int main() {

    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        cnt = 0;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%1d", &map[i][j]);
                check[i][j] = false;
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] != 0 && check[i][j] == false){
//                    cout << "i: " << i << " j: " << j << '\n';
                    bfs(i, j, cnt++);
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
