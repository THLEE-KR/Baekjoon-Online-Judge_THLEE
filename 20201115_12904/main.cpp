#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;

    int len_s, len_t;
    len_s = s.length();
    len_t = t.length();

    while(len_t > len_s) {

        if(t[len_t-1] == 'A'){
            t.pop_back();
        }
        else{
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        len_t = t.length();
//        cout << "t: " << t << '\n';
    }

    if(t == s){
        cout << 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }

    return 0;
}
