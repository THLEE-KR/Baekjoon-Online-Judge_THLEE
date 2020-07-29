#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v(1010);
vector<int> d(1010);
int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    for(int i=0; i<n; i++){
        d[i] = 1;
        for(int j=0; j<i; j++){
            if(v[j] < v[i] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << '\n';

    return 0;
}
