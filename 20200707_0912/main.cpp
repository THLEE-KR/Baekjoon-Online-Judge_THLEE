#include <iostream>
#include <stack>
#include <string>
using namespace std;

void Solve(string str){
    stack<char> stk;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '(')
            stk.push(str[i]);
        else {
            if (stk.empty()) {
                cout << "NO" << '\n';
                return;
            }
            stk.pop();
        }
    }
    if(stk.empty())
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin, str);
        Solve(str);
    }


    return 0;
}
