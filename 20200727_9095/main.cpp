#include <iostream>
using namespace std;

int memo[20];

// top-down
//int go(int i){
//    if(i == 1)
//        return 1;
//    if(i == 2)
//        return 2;
//    if(i == 3)
//        return 4;
//    if(memo[i] > 0)
//        return memo[i];
//
//    memo[i] = go(i-1) + go(i-2) + go(i-3);
//    return memo[i];
//
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    while(n--){
//        int i;
//        cin >> i;
//        cout << go(i) << '\n';
//    }
//
//    return 0;
//}

// bottom-up
int main(){
    int n;
    cin >> n;

    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    for(int i=4; i<11; i++){
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
    }

    while(n--){
        int i;
        cin >> i;
        cout << memo[i] << '\n';
    }

    return 0;
}