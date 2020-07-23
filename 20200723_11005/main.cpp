#include <iostream>
#include <stack>
using namespace std;

void ten2n(int input, int n) {
    stack<char> s;
    while (input != 0) {
        int output = input % n;
        if (output >= 10)
            s.push((char) (output - 10 + 'A'));
        else
            s.push((char) (output + '0'));
        input = input / n;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
int main() {
    int input, n;
    cin >> input >> n;
    ten2n(input, n);
    return 0;
}