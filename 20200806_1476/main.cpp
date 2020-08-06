#include <iostream>
using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;

    int ans = 0;
        for(int i=1; i<INT64_MAX; i++){
        if((((i-1) % 15)+1 == e) && (((i-1) % 28)+1 == s) && (((i-1) % 19)+1 == m)){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}
