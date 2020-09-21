#include <iostream>
#include <vector>
using namespace std;

void go(vector<int> v, int cnt, vector<int> ans){

    if(ans.size() == 6){
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    if(cnt >= v.size())
        return;

    ans.push_back(v[cnt]);
    go(v, cnt+1, ans);
    ans.pop_back();
    go(v, cnt+1, ans);

}


int main() {

    while(true){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }

        vector<int> ans;
        ans.reserve(6);
        ans.push_back(v[0]);
        go(v, 1, ans);
        ans.pop_back();
        go(v, 1, ans);
        cout << '\n';
    }

}
