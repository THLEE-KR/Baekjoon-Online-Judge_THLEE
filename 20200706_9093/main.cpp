#include <iostream>
#include <stack>
#include <string>

using namespace std;

void Solve(string str){
    stack<char> stk;
    for(char c : str){
        if(c == ' ' || c == '\n'){
            while(!stk.empty()){
                cout << stk.top();
                stk.pop();
            }
            cout << c;
        }
        else{
            stk.push(c);
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        string str;
        getline(cin, str);
        str += '\n';
        Solve(str);
    }

    return 0;
}
