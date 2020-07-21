#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(a % b == 0){
        return b;
    }
    else{
        return gcd(b, a % b);
    }
}

int main() {
    int n;
    cin >> n;

    while(n--){
        int m;
        cin >> m;
        vector<int> v(m);
        long long cnt = 0;
        for(int i=0; i<m; i++){
            cin >> v[i];
        }
        for(int i=0; i<m-1; i++){
            for(int j=i+1; j<m; j++){
                cnt += gcd(v[i], v[j]);
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
