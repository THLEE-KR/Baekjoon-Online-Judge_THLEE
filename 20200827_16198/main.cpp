//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int ans = -1;
//
//void go(vector<int> v, const int now, const int n, int sum){
////    cout << "n: " << n << " now: " << now << " sum: " << sum << '\n';
//
//
////    cout << v[now-1] << " " << v[now+1] << '\n';
//    sum += v[now-1] * v[now+1];
////    cout << "sum: " << sum << '\n';
//    if(n-1 == 2){
////        cout << "ans : " << ans << " sum : " << sum << '\n';
//        if(ans < sum){
//            ans = sum;
//        }
//        return;
//    }
//
//    v.erase(v.begin()+now);
//    for(int i=1; i<n-2; i++){
//        go(v, i, n-1, sum);
//    }
//
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
//    int sum = 0;
//    for(int i=1; i<n-1; i++){
//        go(v, i, n, sum);
//    }
//    cout << ans << '\n';
//
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int go(vector<int> &a){
    int n = a.size();
    if(n==2) return 0;
    int ans = 0;
    for(int i=1; i<n-1; i++){
        int energy = a[i-1]*a[i+1];
        vector<int> b(a);
        b.erase(b.begin()+i);
        energy += go(b);
        if(ans < energy){
            ans = energy;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << go(a) << '\n';
    return 0;
}