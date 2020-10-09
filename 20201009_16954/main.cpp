#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <vector>
using namespace std;
bool check[8][8][9];
int dx[] = {0,0,1,-1,1,-1,1,-1,0};
int dy[] = {1,-1,0,0,1,1,-1,-1,0};

int main() {
    int n = 8;
    vector<string> map(n);
    for(int i=0; i<n; i++){
        cin >> map[i];
    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(7,0,0));
    check[7][0][0] = true;

    while(q.empty() == false){
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();
//        cout << "x: " << x << " y: " << y << " z: " << z << '\n';
        if(x == 0 && y == 7){
            cout << 1 << '\n';
            return 0;
        }

        for(int k=0; k<9; k++){
            int nx, ny, nz;
            nx = x + dx[k];
            ny = y + dy[k];
            nz = min(z+1, 8);
            if(nx < 0 || nx > 7 || ny < 0 || ny > 7) continue;
            if(nx-z >= 0 && map[nx-z][ny] == '#') continue;
            if(nx-z-1 >= 0 && map[nx-z-1][ny] == '#') continue;
            if(check[nx][ny][nz] == true) continue;

//            cout << "nx: " << nx << " ny: " << ny << " nz: " << nz << '\n';
            check[nx][ny][nz] = true;
            q.push(make_tuple(nx, ny, nz));

        }


    }
    cout << 0 << '\n';
    return 0;
}
