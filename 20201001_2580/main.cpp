#include <iostream>
using namespace std;
int d[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n = 9;

int square(int x, int y){
    return (x/3)*3 + (y/3);
}

bool go(int z){
    if(z == 81){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << d[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = z/n;
    int y=  z%n;
    if(d[x][y] != 0)
        return go(z+1);
    else{
        for(int i=1; i<=9; i++){
            if(c[x][i] == false && c2[y][i] == false &&
            c3[square(x,y)][i] == false){
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                d[x][y] = i;
                if(go(z+1) == true){
                    return true;
                }
                d[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
        return false;
    }
}

int main() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
            if(d[i][j] != 0){
                c[i][d[i][j]] = true;
                c2[j][d[i][j]] = true;
                c3[square(i,j)][d[i][j]] = true;
            }
        }
    }
    go(0);

    return 0;
}
