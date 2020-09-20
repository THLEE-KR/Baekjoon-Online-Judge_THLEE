#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<int> &v, const vector<char> &bu){
    for(int i=0; i<bu.size(); i++){
      if(bu[i] == '<'){
            if(v[i] >= v[i+1])
                return false;
        }
        else{
            if(v[i] <= v[i+1])
                return false;
        }
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    cout << '\n';
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<char> bu(n);

    for(int i=0; i<n; i++){
        cin >> bu[i];
    }
//    for(int i=0; i<bu.size(); i++){
//        cout << bu[i] << " ";
//    }
//    cout << '\n';

    vector<int> small;
    vector<int> big;
    small.reserve(n+1);
    big.reserve(n+1);
    for(int i=0; i<n+1; i++){
        small.push_back(i);
        big.push_back(9-i);
    }

    while(!check(big, bu)) {
        prev_permutation(big.begin(), big.end());
    }
    while(!check(small, bu)){
        next_permutation(small.begin(), small.end());
    }

    return 0;
}
