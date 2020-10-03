#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 100000000;
int n;
int t[20];
int p[20];
int d[20];

int go(const int day){
    if(day == n+1){
        return 0;
    }
    if(day > n+1){
        return -inf;
    }
    if(d[day] != -1){
        return d[day];
    }
    int t1 = go(day+1);
    int t2 = p[day] + go(day + t[day]);
    d[day] = max(t1, t2);
    return d[day];
}

int main() {
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
        d[i] = -1;
    }
    cout << go(1) << '\n';

    return 0;
}
