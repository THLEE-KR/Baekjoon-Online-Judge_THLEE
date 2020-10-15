//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//struct jewel{
//    int m;
//    int v;
//};
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//
//    vector<jewel> a(n);
//    for(int i=0; i<n; i++){
//        cin >> a[i].m >> a[i].v;
//    }
//
//    sort(a.begin(), a.end(), [](jewel u, jewel v){
//        return u.v > v.v;
//    });
//
//    multiset<int> s;
//    for(int i=0; i<k; i++){
//        int t;
//        cin >> t;
//        s.insert(t);
//    }
//
//    long long ans = 0;
//    for(int i=0; i<n; i++){
//        auto it = s.lower_bound(a[i].m);
//        if(it != s.end()){
//            ans += a[i].v;
//            s.erase(it);
//        }
//    }
//    cout << ans << '\n';
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct jewel{
    int m;
    int v;
    int w;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<jewel> a(n+k);
    for(int i=0; i<n; i++){
        cin >> a[i].m >> a[i].v;
    }
    for(int i=0; i<k; i++){
        cin >> a[i+n].m;
        a[i+n].w = 1;
    }
    sort(a.begin(), a.end(), [](jewel u, jewel v){
        return u.m < v.m || (u.m == v.m && u.w < v.w);
    }); // 보석 사이사이에 가방이 끼도록 정렬
    priority_queue<int> q;
    long long ans = 0;
    for(auto &p : a){
        if(p.w == 0){   // 보석이면
            q.push(p.v);    // 큐에 집어넣음
        }
        else{           // 가방이면
            if(q.empty() == false){     // 큐가 비어있지 않으면
                ans += (long long)q.top();  // 가장 비싼거 더함
                q.pop();
            }
        }
    }
    cout << ans << '\n';

    return 0;
}