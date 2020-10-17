#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        auto it = lower_bound(a.begin(), a.end(), num);

//        cout << "num: " << num << '\n';
//        cout << "a[i]: ";
//        for(int i=0; i<a.size(); i++){
//            cout << a[i] << " ";
//        }
//        cout << '\n';
//        cout << "*it: " << *it << '\n';


        if(it == a.end()){
            a.push_back(num);
        }
        else{
            *it = num;
        };
    }
    cout << a.size() << "\n";

    return 0;
}
