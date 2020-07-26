#include <iostream>
#define MAX 1000000
using namespace std;
int memo[MAX+10];

// top-down
//int go(int n){
//    if(n == 1){
//        return 0;
//    }
//    if(memo[n] > 0){
//        return memo[n];
//    }
//    memo[n] = go(n-1) + 1;
//    if(n%2 == 0){
//        int temp = go(n/2) + 1;
//        if(memo[n] > temp)
//            memo[n] = temp;
//    }
//    if(n%3 == 0){
//        int temp = go(n/3) + 1;
//        if(memo[n] > temp)
//            memo[n] = temp;
//    }
//    return memo[n];
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    int cnt = 0;
//    int ans = go(n);
//    cout << ans << '\n';
//    return 0;
//}

// bottom-up
int main(){
    int n;
    cin >> n;

    memo[1] = 0;
    for(int i=2; i<=n; i++){
        memo[i] = memo[i-1] + 1;
        if(i%2 == 0 && memo[i] > memo[i/2] + 1)
            memo[i] = memo[i/2] + 1;
        if(i%3 == 0 && memo[i] > memo[i/3] + 1)
            memo[i] = memo[i/3] + 1;
    }
    cout << memo[n] << '\n';
    return 0;
}