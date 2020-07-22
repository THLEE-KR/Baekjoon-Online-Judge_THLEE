#include <iostream>
#include <string>
#include <stack>
using namespace std;

void eight2two(string str){
    bool flag = false;

    if(str.length() == 1 && str[0]-'0' == 0){
        cout << "0" << '\n';
        return;
    }

    for(int i=0; i<str.length(); i++){
        stack<int> s;
        int target = str[i] - '0';
        for(int j=0; j<3; j++){
            s.push(target % 2);
            target = target/2;
        }
        while(!s.empty()){
            if(s.top() == 1)
                flag = true;
            if(flag == true)
                cout << s.top();
            s.pop();
        }
    }
    cout << '\n';
}

int main() {
    string str;
    cin >> str;

    eight2two(str);

    return 0;
}
