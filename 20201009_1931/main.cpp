#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for(int i=0; i<n; i++){
        int s, e;
        cin >> s >> e;
        v[i] = make_pair(s, e);
    }

    sort(v.begin(), v.end(),
            [](const pair<int,int> &a,
                    const pair<int,int> &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else {
            return a.second < b.second;
        }
    });

    int cnt = 1;
    int end = v[0].second;
    for(int i=1; i<v.size(); i++){
        if(v[i].first >= end){
            cnt++;
            end = v[i].second;
        }
    }

    cout << cnt << '\n';

    return 0;
}
