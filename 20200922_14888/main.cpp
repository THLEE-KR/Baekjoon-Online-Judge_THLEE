#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> ans;

void go(vector<int> v, vector<int> op, int now, int len, long long sum){
    if(now == len-1){
//        cout << "sum: " << sum << '\n';
        ans.push_back(sum);
        return;
    }
    if(op[0] > 0){
        op[0]--;
        sum = sum + v[now+1];
        go(v, op, now+1, len, sum);
        sum = sum - v[now+1];
        op[0]++;
    }
    if(op[1] > 0){
        op[1]--;
        sum = sum - v[now+1];
        go(v, op, now+1, len, sum);
        sum = sum + v[now+1];
        op[1]++;
    }
    if(op[2] > 0){
        op[2]--;
        sum = sum * v[now+1];
        go(v, op, now+1, len, sum);
        sum = sum / v[now+1];
        op[2]++;
    }
    if(op[3] > 0){
        op[3]--;
        sum = sum / v[now+1];
        go(v, op, now+1, len, sum);
        sum = sum * v[now+1];
        op[3]++;
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    vector<int> op(4);
    for(int i=0; i<4; i++){
        cin >> op[i];
    }

    int now = 0, len = n;
    long long sum = v[0];
    go(v, op, now, len, sum);

    cout << *minmax_element(ans.begin(), ans.end()).second << '\n';
    cout << *minmax_element(ans.begin(), ans.end()).first << '\n';

    return 0;
}
