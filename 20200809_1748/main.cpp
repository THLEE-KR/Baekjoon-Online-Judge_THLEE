#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int value[10];
int main() {
    string str;
    cin >> str;
//    cout << str.length() << '\n';

    for(int i=1; i<10; i++){
        value[i] = i*(pow(10,i)-pow(10,i-1));
    }

    int ans = 0;
    ans += str.length()*(stoi(str) - pow(10, str.length()-1) + 1);
    for(int i=1; i<str.length(); i++){
        ans += value[i];
    }
    cout << ans << '\n';

    return 0;
}
