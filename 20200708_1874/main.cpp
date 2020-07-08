#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n, input;
    cin >> n;
    stack<int> s;
    queue<char> ans;
    int cnt = 0;

    while(n--){
        cin >> input;

        if(s.empty()){
            cnt++;
            s.push(cnt);
            ans.push('+');
        }

        if(input > s.top()){
            while(input != s.top()){
                cnt++;
                s.push(cnt);
                ans.push('+');
            }

            s.pop();
            ans.push('-');
        }
        else if(input == s.top()){
            s.pop();
            ans.push('-');
        }
        else{
            cout << "NO" << '\n';
            return 0;
        }
    }
    while(!ans.empty()){
        cout << ans.front() << '\n';
        ans.pop();
    }

    return 0;
}
