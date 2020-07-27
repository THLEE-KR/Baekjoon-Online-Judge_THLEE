#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10010

vector<int> memo(MAX);
vector<int> v(MAX);

int go(int n){
    if(n == 1)
        return memo[n];
    if(memo[n] > 0)
        return memo[n];


    for(int i=1; i<=n; i++){
        memo[n] = max(memo[n], go(n-i) + v[i]);
    }
//    cout << "n: " << n << " memo: " << memo[n] << '\n';
    return memo[n];

}

int main() {
    int n;
    cin >> n;

    v[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    memo[1] = v[1];
    cout << go(n) << '\n';

    return 0;
}
