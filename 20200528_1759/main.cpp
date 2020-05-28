#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string& str){
    int zaumCnt = 0;
    int moumCnt = 0;
    for(char x : str){
        if(x == 'a' || x == 'e' || x == 'i' ||
        x == 'o' || x == 'u')
            moumCnt += 1;
        else
            zaumCnt += 1;
    }

    return zaumCnt >=2 && moumCnt >= 1;
}

void go(int length, vector<char> v, string str, int i){
    if(str.length() == length){
        if(check(str))
            cout << str << '\n';
        return;
    }
    if(i >= v.size()) return;
    go(length, v, str+v[i], i+1);
    go(length, v, str, i+1);

    return;
}

int main() {
    int len, n;
    cin >> len >> n;

    vector<char> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    go(len, v, "", 0);

    return 0;
}
