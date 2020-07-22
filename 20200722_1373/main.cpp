#include <iostream>
#include <string>
#include <stack>
using namespace std;

void two2eight(string str){
    int n = str.size();
    if(n%3 == 1){
        cout << str[0];
    }
    else if(n%3 == 2){
        cout << (str[0]-'0')*2 + (str[1]-'0');
    }
    for(int i=n%3; i<n; i+=3){
        cout << (str[i]-'0')*4 + (str[i+1]-'0')*2 + (str[i+2]-'0');
    }
}

int main(void){
    string str;
    cin >> str;

    two2eight(str);
    cout << '\n';

    return 0;
}