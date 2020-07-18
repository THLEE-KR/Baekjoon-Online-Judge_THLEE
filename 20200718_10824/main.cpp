#include <iostream>
#include <string>

using namespace std;

int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;

    string str1, str2;
    str1 = to_string(A) + to_string(B);
    str2 = to_string(C) + to_string(D);

    long long answer = stoll(str1) + stoll(str2);
    cout << answer << '\n';

    return 0;
}
