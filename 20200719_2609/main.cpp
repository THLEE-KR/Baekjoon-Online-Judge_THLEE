#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main() {
    int a,b;
    cin >> a >> b;

    int gcdVal = gcd(a,b);
    int lcmVal = a*b/gcdVal;

    cout << gcdVal << '\n' << lcmVal << '\n';


    return 0;
}
