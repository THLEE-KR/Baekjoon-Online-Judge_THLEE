#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10010

int d[MAX];
int input[MAX];

int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> input[i];
    }

    for(int i=1; i<=n; i++){
        if(i==1)
            d[i] = input[i];
        else if(i==2){
            d[i] = input[i-1] + input[i];
        }
        else{
            d[i] = d[i-1];
            if(d[i] < d[i-2] + input[i]){
                d[i] = d[i-2] + input[i];
            }
            if(d[i] < d[i-3] + input[i] + input[i-1]){
                d[i] = d[i-3] + input[i] + input[i-1];
            }
        }
    }

    cout << d[n] << '\n';

    return 0;
}
