#include <iostream>
#define MAX 1000
using namespace std;
int memo[MAX+10];

// top-down
//int go(int n){
//    if(n == 1)
//        return 1;
//    if(n == 2)
//        return 3;
//    if(memo[n] > 0)
//        return memo[n];
//    memo[n] = (go(n-1) + 2*go(n-2))%10007;
//    return memo[n];
//}
//
//int main() {
//    int n;
//    cin >> n;
//    cout << go(n) << '\n';
//    return 0;
//}

// bottom-up
int main() {
    int n;
    cin >> n;

    memo[1] = 1;
    memo[2] = 3;
    for(int i=3; i<=n; i++){
        memo[i] = (memo[i-1] + 2*memo[i-2]) % 10007;
    }
    cout << memo[n];

    return 0;
}
