#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n, n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v(i, j);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << v(i, j);
        }
        cout << '\n';
    }

    return 0;
}
