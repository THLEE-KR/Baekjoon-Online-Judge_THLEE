#include <iostream>
using namespace std;
#define mod 10007
int d[1010][20];

int main() {
    int n;
    cin >> n;

    for(int i=0; i<10; i++){
        d[1][i] = 1;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                d[i][j] += d[i-1][k];
                d[i][j] %= mod;
            }
        }
    }


    int ans = 0;
    for(int i=0; i<10; i++){
        ans += d[n][i];
//        cout << ans << '\n';
        ans %= mod;
    }
    cout << ans << '\n';

    return 0;
}
