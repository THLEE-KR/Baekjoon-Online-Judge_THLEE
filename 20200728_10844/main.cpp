#include <iostream>
using namespace std;
int d[200][20];
#define nom 1000000000

int main() {
    for(int i=1; i<10; i++){
        d[1][i] = 1;
    }

    int n;
    cin >> n;
    int ans = 0;
    if(n > 1){
        for(int i=2; i<=n; i++){
            d[i][0] = d[i-1][1];
            d[i][9] = d[i-1][8];
            for(int j=1; j<9; j++){
                d[i][j] = d[i-1][j-1] + d[i-1][j+1];
            }
            for(int k=0; k<10; k++){
                d[i][k] %= nom;
            }
        }

    }

    for(int i=0; i<10; i++){
        ans += d[n][i];
        ans %= nom;
    }
    cout << ans << '\n';

    return 0;
}
