#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    vector<int> sum(n);
    sum[0] = v[0];
    for(int i=1; i<n; i++){
        if(sum[i-1] + v[i] > v[i])
            sum[i] = sum[i-1] + v[i];
        else
            sum[i] = v[i];
    }

    cout << *max_element(sum.begin(), sum.end()) << '\n';

    return 0;
}
