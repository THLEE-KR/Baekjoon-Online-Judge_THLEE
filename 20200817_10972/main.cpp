#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(vector<int> v){
    int maxi = v.size()-1;
    int maxj = v.size()-1;
    while((maxi > 0) && (v[maxi-1] >= v[maxi]))
        maxi--;
    if(maxi == 0){
        cout << "-1" << '\n';
        return;
    }
    while((maxj > maxi) && (v[maxj] <= v[maxi-1]))
        maxj--;
    if(maxj < maxi){
        cout << "-1" << '\n';
        return;
    }

    swap(v[maxi-1], v[maxj]);
    maxj = v.size()-1;
    while(maxi < maxj){
        swap(v[maxi], v[maxj]);
        maxi++;
        maxj--;
    }

    for(auto e:v){
        cout << e << ' ';
    }
    cout << '\n';

}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    check(v);

    return 0;
}
