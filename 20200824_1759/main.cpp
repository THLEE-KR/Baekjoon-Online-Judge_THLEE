#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void go(vector<char>& v, vector<char>& ans, int now, int goal){
    ans.push_back(v[now]);

    if(ans.size() == goal){
        for(int i=0; i<ans.size(); i++){
            cout << ans[i];
        }
        cout << '\n';
        return;
    }
    if(now >= v.size())
        return;

    for(int i=now+1; i<goal; i++){
        go(v, ans, i, goal);
    }
    return;
}

int main() {
    int r, n;
    cin >> r >> n;

    vector<char> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<char> ans;
    for(int i=0; i<n; i++)
        go(v, ans, i, r);

    return 0;
}
