#include <iostream>
#include <vector>
#include <algorithm>

struct Money{
    int i;
    int t;
};

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<Money> v(n);

    for(int i=0; i<n; i++){
        v[i].i = i;
        cin >> v[i].t;
    }

    sort(v.begin(), v.end(), [](const Money &a, const Money &b){
        return a.t < b.t;
    });

//    for(int i=0; i<n; i++){
//       cout << v[i].t << " ";
//    }
//    cout << '\n';

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += v[i].t * (n-i);
    }
    cout << ans << '\n';

    return 0;
}
