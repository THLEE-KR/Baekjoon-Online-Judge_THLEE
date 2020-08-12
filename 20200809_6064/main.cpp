#include <iostream>
#include <vector>
using namespace std;

int check(int n, int m, vector<int> &v){
    int ans = -1;
//    cout << n << " " << m  << " " << v[0] << " " << v[1] << " " << '\n';

    if(v[0] == 0 || v[1] == 0 || v[0] > n || v[1] > m)
        return ans;

    for(int cnt=v[0]; cnt<=(n*m); cnt+=n){
        if((cnt-1)%n+1 == v[0] && (cnt-1)%m+1 == v[1]){
            ans = cnt;
            break;
        }
    }

    return ans;
}

int main() {
    int num;
    cin >> num;

    while(num--){
        int n, m;
        vector<int> v(2);
        cin >> n >> m;
        cin >> v[0] >> v[1];
        cout << check(n, m, v) << '\n';
    }

    return 0;
}
