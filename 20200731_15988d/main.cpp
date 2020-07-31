#include <iostream>
#define MAX 1000000
#define mod 1000000009
using namespace std;

int d[MAX];
int go(int m){
    d[1] = 1; d[2] = 2; d[3] = 4;
    if(d[m] != 0)
        return d[m];

    for(int i=1; i<=3; i++){
        d[m] += go(m-i);
        d[m] %= mod;
    }
    return d[m] % mod;

}

int main() {
    int n;
    cin >> n;

    while(n--){
        int m;
        cin >> m;
        cout << go(m) << '\n';
    }

    return 0;
}
