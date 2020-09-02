#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int data[100010];

int main() {
    int s, e;
    cin >> s >> e;

    queue<int> q;
    q.push(s);
    data[s] = 1000000;

    vector<int> route[100010];

    while(!q.empty()){
        int now = q.front();
        q.pop();
        vector<int> next;
        next.push_back(now+1);
        next.push_back(now-1);
        next.push_back(now*2);
        for(int i=0; i<next.size(); i++){
            if(next[i] < 0 || next[i] > 100000) continue;
            if(data[next[i]] > 0) continue;
//            cout << "next[i]: " << next[i] << '\n';
            data[next[i]] = data[now] + 1;
            q.push(next[i]);
            route[next[i]].push_back(now);
        }
    }

    cout << data[e] - data[s] << '\n';

    vector<int> ans;
    ans.push_back(e);
//    cout << e << " ";
    while(e != s){
//        cout << route[e][0] << " ";
        ans.push_back(route[e][0]);
        e = route[e][0];
    }

    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
