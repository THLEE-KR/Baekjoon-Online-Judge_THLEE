#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s;
    vector<int> a(n);
    vector<int> ans(n);
    vector<int> cnt(1000000, 0);
    for(int i=0; i<n; i++){
        cin >> a[i];
        cnt[a[i]] += 1;
    }

    s.push(0);
    for(int i=1; i<n; i++){
        if(s.empty()){
            s.push(i);
        }
//        cout << "cnt[a[s.top()]]: " << cnt[a[s.top()]] << " cnt[a[i]]: " << cnt[a[i]] << '\n';
        while(!s.empty() && cnt[a[s.top()]] < cnt[a[i]]){
            ans[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        ans[s.top()] = -1;
        s.pop();
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}