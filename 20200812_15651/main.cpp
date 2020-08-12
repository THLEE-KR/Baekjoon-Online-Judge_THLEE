#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool    c[10];
int     a[10];
void go(int n, int m, int cnt, vector<int> v){
    if(cnt == m){
        for(int i=0; i<cnt; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++){
        if(c[i] != true){
            c[i] = true;
            a[cnt] = v[i];
            go(n, m, cnt+1, v);
            c[i] = false;
        }
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    go(n, m, cnt, v);

    return 0;
}