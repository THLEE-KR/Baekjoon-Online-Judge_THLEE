#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    vector<int> v(26, 0);

    for(int i=0; i<str.length(); i++){
        v[str[i] - 'a'] += 1;
    }

    for(int i=0; i<26; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}
