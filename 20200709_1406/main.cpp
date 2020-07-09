#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> leftStk;
stack<char> rightStk;

void Solve(char ch){
    if(ch == 'L'){
        if(!leftStk.empty()){
            rightStk.push(leftStk.top());
            leftStk.pop();
        }
    }
    else if(ch == 'D'){
        if(!rightStk.empty()){
            leftStk.push(rightStk.top());
            rightStk.pop();
        }
    }
    else if(ch == 'B'){
        if(!leftStk.empty()){
            leftStk.pop();
        }
    }
    else{
        char ch2;
        cin >> ch2;
        leftStk.push(ch2);
    }
}

void printAns(){
    while(!leftStk.empty()){
        rightStk.push(leftStk.top());
        leftStk.pop();
    }
    while(!rightStk.empty()){
        cout << rightStk.top();
        rightStk.pop();
    }
}

int main() {
    string input;
    getline(cin, input);
//    cout << "input : " << input << '\n';

    for(int i=0; i<input.size(); i++){
        leftStk.push(input[i]);
    }

    int n;
    cin >> n;
//    cout << "n: " << n << '\n';
    while(n--){
        char ch;
        cin >> ch;
//        cout << "ch : " << ch << '\n';
        Solve(ch);
    }

    printAns();

    return 0;
}
