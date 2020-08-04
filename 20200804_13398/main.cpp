#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n+10, -9999);

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    vector<long long> dl(n+10, -9999);
    vector<long long> dr(n+10, -9999);
    vector<long long> sumdldr(n+10, -9999);

    dl[1] = v[1];
    for(int i=2; i<=n; i++){
        dl[i] = max(dl[i-1] + v[i], v[i]);
    }

    dr[n] = v[n];
    for(int i=n-1; i>=1; i--){
        dr[i] = max(dr[i+1] + v[i], v[i]);
    }

    for(int i=1; i<=n; i++){
        sumdldr[i] = dr[i+1] + dl[i-1];
    }

    long long ans1 = *max_element(sumdldr.begin(), sumdldr.end());
    long long ans2 = *max_element(dl.begin(), dl.end());
    cout << max(ans1, ans2) << '\n';

    return 0;
}
