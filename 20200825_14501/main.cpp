#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;

void go(vector<int> &T, vector<int> &P, int day, int sum, int length){
    if(day == length+1){
        if(ans < sum)
            ans = sum;
        return;
    }
    if(day > length+1)
        return;
    go(T, P, day+1, sum, length);
    go(T, P, day+T[day], sum+P[day], length);
}

int main() {
    int n;
    cin >> n;
    vector<int> T(n+1);
    vector<int> P(n+1);
    for(int i=1; i<=n; i++){
        cin >> T[i] >> P[i];
    }

    int day = 1;
    int sum = 0;
    int length = n;
    go(T, P, day, sum, length);

    cout << ans << '\n';

    return 0;
}
