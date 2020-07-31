#include <iostream>
#define MAX 100000
#define mod 9901
using namespace std;
long long d[MAX+10][5];

int main() {
    int n;
    cin >> n;

    d[1][0] = 1; d[1][1] = 1; d[1][2] = 1;
    for(int i=2; i<=n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1] + d[i-1][2];
        d[i][1] = d[i-1][0] + d[i-1][2];
        d[i][2] = d[i-1][0] + d[i-1][1];
        for(int j=0; j<3; j++){
            d[i][j] %= mod;
        }
    }
    cout << (d[n][0] + d[n][1] + d[n][2]) % mod << '\n';

    return 0;
}
