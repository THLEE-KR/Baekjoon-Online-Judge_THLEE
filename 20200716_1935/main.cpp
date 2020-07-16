#include <iostream>
#include <stack>
#include <iomanip>
#include <string>

using namespace std;
int operand[26];
double Solve(string str, int* v){
    stack<double> s;
    double result = 0;
    for(char ch : str){
//        cout << "str[i]: " << str[i] << '\n';
        if(ch >= 'A' && ch <= 'Z'){
            s.push(v[ch-'A']);
//            cout << "push: " << str[i]-'A'+1 << '\n';
        }
        else{
            double first = s.top();
//            cout << "first: " << first << '\n';
            s.pop();
            double second = s.top();
//            cout << "second: " << second << '\n';
            s.pop();
            if(ch == '+')
                result = second + first;
            else if(ch == '-')
                result = second - first;
            else if(ch == '*')
                result = second * first;
            else if(ch == '/')
                result = second / first;
            s.push(result);
//            cout << "result: " << result << '\n';
        }
    }
    return s.top();
}

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    for(int i=0; i<n; i++){
        cin >> operand[i];
    }

    double ans = Solve(str, operand);
    cout << fixed << setprecision(2) << ans << '\n';

    return 0;
}
