#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char ch){
    if(ch == '(') return 0;
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}

void Solve(string input) {
    stack<char> sOp;
    string ans;
    for(char ch : input){
        if(ch >= 'A' && ch <= 'Z')
            ans += ch;
        else if(ch == '(')
            sOp.push(ch);
        else if(ch == ')'){
            while(sOp.top() != '('){
                ans += sOp.top();
                sOp.pop();
            }
            sOp.pop();
        }
        else{
            while(!sOp.empty() && precedence(sOp.top()) >= precedence(ch)){
                ans += sOp.top();
                sOp.pop();
            }
            sOp.push(ch);
        }
    }
    while(!sOp.empty()){
        ans += sOp.top();
        sOp.pop();
    }
    cout << ans << '\n';
}

int main() {
    string input;
    cin >> input;

    Solve(input);

    return 0;
}
