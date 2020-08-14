#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void go(int n, int m, int start, int len, vector<int> v, vector<int> ans){
    if(len == m){
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++){
        if(i < start) continue;

        ans[len] = v[i];
        go(n, m, i, len+1, v, ans);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v;
    vector<int> ans(m);
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        for(int j=0; j<v.size(); j++){
            if(v[j] == input)
                continue;
            v.push_back(input);
        }
    }

    sort(v.begin(), v.end());
    go(n, m,0, 0, v, ans);

    return 0;
}