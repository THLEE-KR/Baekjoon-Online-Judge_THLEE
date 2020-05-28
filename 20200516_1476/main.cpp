#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    int E = 15;
    int S = 28;
    int M = 19;

    for(int i=0; i<3; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    for(int i=1; i<=15*28*19; i++){
        int a = 0;
        int b = 0;
        int c = 0;

        if(i % E == 0)
            a = E;
        else
            a = i % E;

        if(i % S == 0)
            b = S;
        else
            b = i % S;

        if(i % M == 0)
            c = M;
        else
            c = i % M;


//        cout << a << " " << b << " " << c << '\n';
//        cout << v[0] << " " << v[1] << " " << v[2] << '\n';
        if((a == v[0]) && (b == v[1]) && (c == v[2])){
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
