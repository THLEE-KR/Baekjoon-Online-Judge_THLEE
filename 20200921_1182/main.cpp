#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void go(const vector<int> &v, const int idx, const int s, int sum, int num){
    if(idx == v.size()){
        if(num == 0)
            return;
        if(s == sum)
            cnt++;
        return;
    }

    sum += v[idx];
    num += 1;
//    cout << sum << '\n';
    go(v, idx+1, s, sum, num);
    sum -= v[idx];
    num -= 1;
//    cout << sum << '\n';
    go(v, idx+1, s, sum, num);

}

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int idx = 0, sum = 0, num = 0;
    go(v, idx, s, sum, num);
    cout << cnt << '\n';

    return 0;
}
