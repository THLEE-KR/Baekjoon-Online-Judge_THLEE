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

    vector<int> dup(n);
    vector<int> ddown(n);
    for(int i=0; i<n; i++){
        dup[i] = 1;
        for(int j=0; j<i; j++){
            if(v[j] < v[i] && dup[j] + 1 > dup[i])
                dup[i] = dup[j] + 1;
        }
    }
    for(int i=n-1; i>=0; i--){
        ddown[i] = 1;
        for(int j=n-1; j>i; j--){
            if(v[i] > v[j] && ddown[j] + 1 > ddown[i])
                ddown[i] = ddown[j] + 1;
        }
    }
    vector<int> dtotal(n);
    for(int i=0; i<n; i++){

        dtotal[i] = dup[i] + ddown[i]-1;
    }
    cout << *max_element(dtotal.begin(), dtotal.end()) << '\n';

    return 0;
}
