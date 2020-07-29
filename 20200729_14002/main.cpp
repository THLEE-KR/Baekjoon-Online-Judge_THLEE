#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<int> v(1010);
vector<int> d(1010);
vector<int> ans(1010, -1);
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
                ans[i] = j;
            }
        }
    }
    int max_elem = *max_element(d.begin(), d.end());
    cout << max_elem << '\n';
    int max_idx = 0;
    for(int i=0; i<n; i++){
        if(d[i] == max_elem){
            max_idx = i;
            break;
        }
    }

    stack<int> s;
    while(max_idx != -1){
//        cout << v[max_idx] << ' ';
        s.push(v[max_idx]);
        max_idx = ans[max_idx];
    }
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';

    return 0;
}