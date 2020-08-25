#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool check(string &password){
    int cnt_ja = 0;
    int cnt_mo = 0;
    for(int i=0; i<password.size(); i++){
        if(password[i] == 'a' || password[i] == 'e' || password[i] == 'i' ||
                password[i] == 'o' || password[i] == 'u' )
            cnt_mo++;
        else
            cnt_ja++;
    }
    if(cnt_ja >=2 && cnt_mo >= 1)
        return true;
    else
        return false;

}

void go(int length, vector<char> &v, string password, int i){
    if(password.length() == length){
        if(check(password))
            cout << password << '\n';
        return;
    }
    if(i == v.size())
        return;
    go(length, v, password+v[i], i+1);
    go(length, v, password, i+1);
}

int main() {
    int r, n;
    cin >> r >> n;

    vector<char> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    string password = "";
    go(r, v, password, 0);

    return 0;
}