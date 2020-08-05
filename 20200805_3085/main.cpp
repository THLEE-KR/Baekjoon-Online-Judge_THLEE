#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int check(char d[][55], int n){
    int maxV = 1;

    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n-1; j++){
            if(d[i][j] == d[i][j+1])
                cnt++;
            else
                cnt = 1;
            if(maxV < cnt)
                maxV = cnt;
        }
    }


    for(int j=0; j<n; j++){
        int cnt = 1;
        for(int i=0; i<n-1; i++){
            if(d[i][j] == d[i+1][j])
                cnt++;
            else
                cnt = 1;
            if(maxV < cnt)
                maxV = cnt;
        }
    }

    return maxV;
}


int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j+1 < n){
                swap(a[i][j], a[i][j+1]);
                int temp = check(a);
                if(ans < temp)
                    ans = temp;
                swap(a[i][j], a[i][j+1]);
            }
            if(i+1 < n){

            }
        }
    }
    cout << ans << '\n';

    return 0;
}
