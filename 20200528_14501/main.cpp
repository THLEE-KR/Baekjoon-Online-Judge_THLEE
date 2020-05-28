#include <iostream>

using namespace std;

int ans;
int n;

int T[21];
int P[21];

void go(int day, int sum){
    if(day == n){
        if(ans < sum) ans = sum;
        return;
    }
    if(day > n){
        return;
    }
    go(day+1, sum);
    go(day+T[day], sum+P[day]);
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> T[i] >> P[i];
    }

    go(0, 0);
    cout << ans << '\n';

    return 0;
}
