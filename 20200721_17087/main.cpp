#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main() {
    int n, input;
    cin >> n >> input;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        int n2;
        cin >> n2;

        if(input - n2 > 0)
            v[i] = input - n2;
        else
            v[i] = n2 - input;
    }

    int a = v[0];
    for(int i=1; i<n; i++){
        int b = v[i];
        a = gcd(a, b);
    }
    cout << a << '\n';



    return 0;
}
