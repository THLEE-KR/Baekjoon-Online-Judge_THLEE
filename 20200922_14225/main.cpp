#include <iostream>
#include <vector>
using namespace std;

bool check[2000000];

void go(vector<int> v, int now, int sum, int len){
    if(now >= len){
        check[sum] = true;
        return;
    }

    sum += v[now];
//    cout << "sum: " << sum << '\n';
    go(v, now+1, sum, len);
    sum -= v[now];
//    cout << "sum: " << sum << '\n';
    go(v, now+1, sum, len);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int now = 0, sum = 0, len = n;
    go(v, now, sum, len);

    for(int i=1; i<2000000; i++){
        if(check[i] == false){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
