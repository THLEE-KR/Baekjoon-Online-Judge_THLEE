#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010
int d[MAX][5];
int res[MAX][5];

int go(int m){
    res[1][1] = d[1][1];
    res[1][2] = d[1][2];
    for(int i=2; i<=m; i++){
        res[i][2] = max(res[i-1][0] + d[i][2],
                res[i-1][1] + d[i][2]);
        res[i][1] = max(res[i-1][0] + d[i][1],
                res[i-1][2] + d[i][1]);
        res[i][0] = max(max(res[i-1][0],
                res[i-1][1]), res[i-1][2]);
    }
    return max(max(res[m][0], res[m][1]), res[m][2]);
}

int main() {
    int n;
    cin >> n;

    while(n--){
        int m;
        cin >> m;
        for(int i=1; i<=m; i++)
            cin >> d[i][1];
        for(int i=1; i<=m; i++)
            cin >> d[i][2];
        cout << go(m) << '\n';
    }

    return 0;
}
