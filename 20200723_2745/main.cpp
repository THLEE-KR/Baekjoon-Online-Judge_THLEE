#include <iostream>
#include <string>
#include <stack>
using namespace std;

void n210(string str, int n){
    int number = 0;
    int len = str.length();
    int gop = 1;
    for(int i=len-1; i>=0; i--){
        if(str[i] >= 'A'){
            number += ((int)(str[i] - 'A') + 10)*gop;
        }
        else{
            number += (int)(str[i] - '0')*gop;
        }
        gop *= n;
    }
    cout << number << '\n';
}

int main() {
    int n;
    string str;
    cin >> str >> n;
    n210(str, n);
    return 0;
}
