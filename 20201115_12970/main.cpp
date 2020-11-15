#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    for(int a=0; a<=n; a++){
//        cout << "a: " << a << '\n';
        int b = n-a;
//        cout << "b: " << b << '\n';
        if(a*b < k) continue;

        vector<int> cnt(b+1);
        for(int i=0; i<a; i++){
            int x = min(b,k);
//            cout << "x: " << x << '\n';
            cnt[x] += 1;
//            cout << "cnt[x]: " << cnt[x] << '\n';
            k -= x;
//            cout << "k: " << k << '\n';
        }
        for(int i=b; i>=0; i--){
            for(int j=0; j<cnt[i]; j++){
                cout << 'A';
            }
            if(i>0){
                cout << 'B';
            }
        }
        cout << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}
