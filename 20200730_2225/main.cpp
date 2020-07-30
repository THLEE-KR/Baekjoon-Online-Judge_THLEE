#include <iostream>
#define MAX 300
#define mod 1000000000
using namespace std;
long long d[MAX][MAX];

int main() {
    int n,k;
    cin >> n >> k;

    for(int i=0; i<=n; i++){
        d[i][1] = 1LL;
        for(int j=2; j<=k; j++){
            for(int m=0; m<=i; m++){
                d[i][j] += d[m][j-1];
            }
            d[i][j] %= mod;
        }
    }
    cout << d[n][k] << '\n';

    return 0;
}
