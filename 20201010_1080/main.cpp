#include <iostream>
#include <cstdio>
using namespace std;

int a[50][50];
int b[50][50];

void flip(const int i, const int j){
    for(int k=i-1; k<=i+1; k++){
        for(int l=j-1; l<=j+1; l++){
            a[k][l] = 1-a[k][l];
//            cout << "k: " << k << " l: " << l << '\n';
//            cout << "a[k][l]: " << a[k][l] << '\n';
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &b[i][j]);
        }
    }

    int ans = 0;
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-2; j++){
//            cout << "i: " << i << " j: " << j << '\n';
//            cout << "a[i][j]: " << a[i][j] << " b[i][j]: " << b[i][j] << '\n';
            if(a[i][j] != b[i][j]){
                ans++;
                flip(i+1, j+1);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] != b[i][j]){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
