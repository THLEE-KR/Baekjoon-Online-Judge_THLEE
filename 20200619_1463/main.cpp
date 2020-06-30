#include <iostream>

using namespace std;
int ans = INT32_MAX;
void go(int n, int cnt){
    if(n == 1){
        if(ans > cnt)
            ans = cnt;
        return;
    }
    if(n % 3 == 0){
        go(n/3, cnt+1);
    }
    if(n % 2 == 0){
        go(n/2, cnt+1);
    }
    go(n-1, cnt+1);
}

int main() {
    int n;
    cin >> n;
    go(n, 0);
    cout << ans << '\n';
    return 0;
}
