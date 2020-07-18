#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    int len = str.length();
    vector<string> v(len);
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++)
            v[i] += str[j];
    }

    sort(v.begin(), v.end());

    for(int i=0; i<len; i++){
        cout << v[i] << '\n';
    }

    return 0;
}
