#include <iostream>
using namespace std;


bool    c[10];
int     a[10];
void go(int n, int m, int cnt){
    if(cnt == m){
        for(int i=0; i<cnt; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++){
        if(c[i] != true){
            a[cnt] = i;
            c[i] = true;
            go(n, m, cnt+1);
            c[i] = false;
        }
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    go(n, m, cnt);

    return 0;
}
