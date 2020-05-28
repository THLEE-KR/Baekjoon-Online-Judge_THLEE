#include <iostream>
using namespace std;
long long d[100];

int main(void){
    int n;
    cin >> n;

    d[2] = 3;
    for(int i=4; i<=n; i+=2){
        d[i] = 3*d[i-2];
        for(int j=i-4; j>=0; j-=2){
            d[i] += 2*d[j];
        }
    }

    cout << d[n] << '\n';

    return 0;
}
