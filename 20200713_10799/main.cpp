#include <iostream>
#include <string>
#include <stack>

using namespace std;

void Solve(string str){
    stack<char> stk;
    int cnt = 0;
    bool flag = false;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '('){
            flag = true;
            stk.push(str[i]);
        }
        else{
            if(flag == true){
                stk.pop();
                cnt += stk.size();
//                cout << stk.size() << '\n';
            }
            else{
                stk.pop();
                cnt += 1;
//                cout << "1" << '\n';
            }
            flag = false;
        }
    }
    cout << cnt << '\n';
}

int main() {
    string inputStr;
    getline(cin, inputStr);

    Solve(inputStr);

    return 0;
}
