#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;

    int n;
    cin >> n;

    int ten = 0;
    int gop = pow(A, n-1);
    while(n--){
        int input;
        cin >> input;
        ten += input*gop;
        gop /= A;
    }

    stack<int> s;
    while(ten / B != 0){
        s.push(ten % B);
        ten /= B;
    }
    s.push(ten);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << '\n';

    return 0;
}
