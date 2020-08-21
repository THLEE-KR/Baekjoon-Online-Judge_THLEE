#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int> v){
    int value = 0;
    for(int i=1; i<v.size(); i++){
        value += abs(v[i] - v[i-1]);
    }
    return value;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n;
    i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int maxValue = check(v);

    while(1){
        bool Flag = next_permutation(v.begin(), v.end());
        if(Flag == false)
            break;
        if(maxValue < check(v))
            maxValue = check(v);
    }

    cout << maxValue << '\n';
    return 0;
}
