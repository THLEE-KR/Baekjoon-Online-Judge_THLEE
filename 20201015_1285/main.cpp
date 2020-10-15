#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

char flip(char x){
    if(x == 'H') return 'T';
    else return 'H';
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int ans = n*n;
    for(int state=0; state<(1<<n); state++){
        int sum = 0;
        for(int j=0; j<n; j++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                char cur = v[i][j];
                if(state & (1<<i)){
                    cur = flip(cur);
                }
                if(cur == 'T'){
                    cnt += 1;
                }
            }
            sum += min(cnt, n-cnt);
        }
        if( ans > sum) ans = sum;
    }
    cout << ans << '\n';

    return 0;
}
