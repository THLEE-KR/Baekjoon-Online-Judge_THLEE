#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v2d;
    vector<int> vPerm(n);
    for(int i=0; i<n; i++){
        vector<int> v1d(n);
        for(int j=0; j<n; j++){
            cin >> v1d[j];
        }
        v2d.push_back(v1d);
    }

    for(int i=0; i<n; i++){
        vPerm[i] = i;
    }

    int minValue = 90000000;
    do{
        int sumValue = 0;
        bool ok = true;
        int len = vPerm.size();
        for(int i=1; i<=len; i++){
            if(v2d[vPerm[i-1]][vPerm[i % len]] == 0)
                ok = false;
            else
                sumValue += v2d[vPerm[i-1]][vPerm[i % len]];
        }
        if(ok == true)
            minValue = min(sumValue, minValue);
    }while(next_permutation(vPerm.begin(), vPerm.end()));

    cout << minValue << '\n';
    return 0;
}
