#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, ans;
    getline(cin, str);

    int len = str.length();
    for(int i=0; i<len; i++){
        char c = str[i] + 13;
        if(str[i] >= 'a' && str[i] <= 'z'){
            if(str[i] + 13 > 'z')
                c = 'a' + (str[i] + 13 - 'z' - 1);
            ans += c;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            if(str[i] + 13 > 'Z')
                c = 'A' + (str[i] + 13 - 'Z' - 1);
            ans += c;
        }
        else{
            ans += str[i];
        }
    }

    cout << ans << '\n';

    return 0;
}