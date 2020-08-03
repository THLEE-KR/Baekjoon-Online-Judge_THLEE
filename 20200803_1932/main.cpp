#include <iostream>
#include <algorithm>
using namespace std;

int s[510][510];
int d[510][510];

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> s[i][j];
        }
    }

    d[1][1] = s[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
                d[i][j] = d[i-1][j] + s[i][j];
            }
            else if(j==i){
                d[i][j] = d[i-1][j-1] + s[i][j];
            }
            else{
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + s[i][j];
            }
        }
    }

    int ans = d[n][1];
    for(int i=2; i<=n; i++){
        ans = max(ans, d[n][i]);
    }
    cout << ans << '\n';

    return 0;
}
