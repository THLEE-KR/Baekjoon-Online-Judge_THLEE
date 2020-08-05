#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(9);
    int sum = 0;
    for(int i=0; i<9; i++){
        cin >> v[i];
        sum += v[i];
    }

    int sum2 = 0;
    int check1 = 0;
    int check2 = 0;
    for(int i=0; i<9; i++){
        sum2 = 0;
        for(int j=i+1; j<9; j++){
            sum2 = v[i] + v[j];
            if(sum2 == sum - 100){
//                cout << "i: " << i << " j: " << j << '\n';
                check1 = i;
                check2 = j;
            }
        }
    }

    v.erase(v.begin() + check1);
    v.erase(v.begin() + check2 - 1);
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}
