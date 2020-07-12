#include <iostream>
#include <string>
#include <deque>

using namespace std;

void Solve(string str){
    int cnt = 0;
    deque<char> deq;

//    cout << "str.length(): " << str.length() << '\n';
    while(cnt < str.length()){
//        cout << "cnt: " << cnt << '\n';
        if(str[cnt] == '<'){
            while(str[cnt] != '>'){
                deq.push_back(str[cnt]);
//                cout << "str[cnt]: " << str[cnt] << '\n';
                cnt++;
            }
            while(!deq.empty()){
                cout << deq.front();
                deq.pop_front();
            }
            cout << str[cnt];
            cnt++;
        }
        else{
            while(str[cnt] != ' ' && str[cnt] != '<' && cnt < str.length()){
                deq.push_back(str[cnt]);
//                cout << "str[cnt]: " << str[cnt] << '\n';
                cnt++;
            }
            while(!deq.empty()){
                cout << deq.back();
                deq.pop_back();
            }
            if(str[cnt] == ' ' || str[cnt] == '\n'){
                cout << str[cnt];
                cnt++;
            }
        }

    }
}

int main() {
    string str;
    getline(cin, str);
    Solve(str);
    return 0;
}
