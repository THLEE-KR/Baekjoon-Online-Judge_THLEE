//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<long long> ans;
//
//void go(const vector<int> v, vector<int> op, const int now, long long sum){
//    if(now == v.size()-1){
//        ans.push_back(sum);
//        return;
//    }
//    if(op[0] > 0){
//        op[0]--;
//        go(v, op, now+1, sum + v[now+1]);
//        op[0]++;
//    }
//    if(op[1] > 0){
//        op[1]--;
//        go(v, op, now+1, sum - v[now+1]);
//        op[1]++;
//    }
//    if(op[2] > 0){
//        op[2]--;
//        go(v, op, now+1, sum * v[now+1]);
//        op[2]++;
//    }
//    if(op[3] > 0){
//        op[3]--;
//        go(v, op, now+1, sum / v[now+1]);
//        op[3]++;
//    }
//    return;
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> v(n);
//    for(int i=0; i<n; i++){
//        cin >> v[i];
//    }
//
//    vector<int> op(4);
//    for(int i=0; i<4; i++){
//        cin >> op[i];
//    }
//
//    int now = 0;
//    long long sum = v[0];
//    go(v, op, now, sum);
//
//
////    for(auto a : ans){
////        cout << a << '\n';
////    }
//    cout << *minmax_element(ans.begin(), ans.end()).second << '\n';
//    cout << *minmax_element(ans.begin(), ans.end()).first << '\n';
//
//    return 0;
//}

//----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> ans;

pair<int, int> calc(vector<int> &a, int index, int cur,
        int plus, int minus, int mul, int div){
    int n = a.size();
    if(index == n){
        return make_pair(cur, cur);
    }
    vector<pair<int,int>> res;
    if(plus > 0){
        res.push_back(calc(a,index+1,cur+a[index],
                plus-1,minus,mul,div));
    }
    if(minus > 0){
        res.push_back(calc(a,index+1,cur-a[index],
                           plus,minus-1,mul,div));
    }
    if(mul > 0){
        res.push_back(calc(a,index+1,cur*a[index],
                           plus,minus,mul-1,div));
    }
    if(div > 0){
        res.push_back(calc(a,index+1,cur/a[index],
                           plus,minus,mul,div-1));
    }
    auto ans = res[0];
    for(auto p : res){
        if(ans.first < p.first){
            ans.first = p.first;
        }
        if(ans.second > p.second){
            ans.second = p.second;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;
    auto p = calc(a, 1, a[0], plus, minus, mul, div);
    cout << p.first << '\n';
    cout << p.second << '\n';
    return 0;
}
