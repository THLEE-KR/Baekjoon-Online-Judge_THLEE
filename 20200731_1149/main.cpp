#include <iostream>
#include <algorithm>
using namespace std;
int v[1010][10];
int ans[1010][10];

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    for(int i=0; i<3; i++)
        ans[0][i] = v[0][i];

    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++)
            ans[i][j] = min(ans[i-1][(j+1)%3] + v[i][j],
                            ans[i-1][(j+2)%3] + v[i][j]);
    }

//    for(int i=0; i<3; i++){
//        int result = min(ans[i][0], ans[i][1]);
//        cout << min(result, ans[i][2]) << '\n';
//    }
    int result = min(ans[n-1][0], ans[n-1][1]);
    cout << min(result, ans[n-1][2]) << '\n';


    return 0;
}
