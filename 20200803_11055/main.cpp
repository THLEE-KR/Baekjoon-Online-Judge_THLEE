#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1010
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> d(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    for(int i=0; i<n; i++){
//        cout << "i: " << i << '\n';
        d[i] = v[i];
        for(int j=0; j<i; j++){
            if((v[j] < v[i]) && (d[j]+v[i] > d[i])){
                d[i] = d[j] + v[i];
            }
        }
//        cout << d[i] << '\n';
    }

    cout << *max_element(d.begin(), d.end()) << '\n';

    return 0;
}
