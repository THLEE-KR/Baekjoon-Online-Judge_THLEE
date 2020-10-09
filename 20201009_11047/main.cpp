#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int check_idx = n-1;
    int ans = 0;
    for(int i=check_idx; i>= 0; i--){
        if(k >= v[i]){
//                cout << "v[i]: " << v[i] << '\n';
            ans += k/v[i];
            k %= v[i];
        }
    }
    cout << ans << '\n';

    return 0;
}
