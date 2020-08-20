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

    int i = n-1;
    int j = n-1;
    while(v[i-1] <= v[i] && i > 0)
        i--;
    if(i <= 0){
        cout << -1 << '\n';
        return 0;
    }

    while(v[j] >= v[i-1])
        j--;
    swap(v[i-1], v[j]);

    j = n-1;
    while(i < j){
        swap(v[i], v[j]);
        i++;
        j--;
    }

    for(int k=0; k<n; k++){
        cout << v[k] << " ";
    }
    cout << '\n';

    return 0;
}
