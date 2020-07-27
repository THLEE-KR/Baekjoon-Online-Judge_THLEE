#include <iostream>
#define MAX 100000
long long memo[MAX + 10][10];
using namespace std;
const long long mod = 1000000009L;

int main() {
    int n;
    cin >> n;

    memo[1][1] = 1;
    memo[2][2] = 1;
    memo[3][1] = 1; memo[3][2] = 1; memo[3][3] = 1;

    for(int i=4; i<=MAX; i++){
        memo[i][1] = memo[i-1][2] + memo[i-1][3];
        memo[i][1] %= mod;
        memo[i][2] = memo[i-2][1] + memo[i-2][3];
        memo[i][2] %= mod;
        memo[i][3] = memo[i-3][1] + memo[i-3][2];
        memo[i][3] %= mod;
    }

    while(n--){
        int input;
        cin >> input;
        cout << (memo[input][1] + memo[input][2] + memo[input][3]) % mod << '\n';
    }

    return 0;
}
