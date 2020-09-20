#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char alpha[256];

int calc(const vector<string> &num, const vector<char> &letters, const vector<int> &d){
    int len = letters.size();
    int sum = 0;
    for(int i=0; i<len; i++){
        alpha[letters[i]] = d[i];
    }
    for(string s : num){
        int now = 0;
        for(char x : s){
            now = now*10 + alpha[x];
        }
        sum += now;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<string> num(n);
    vector<char> letters;
    for(int i=0; i<n; i++){
        cin >> num[i];
        for(char x : num[i]){
            letters.push_back(x);
        }
    }
    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());
    int len = letters.size();
    vector<int> d;
    for(int i=9; i>9-len; i--){
        d.push_back(i);
    }
    sort(d.begin(), d.end());
    int ans = 0;
    do{
        int now = calc(num, letters, d);
        if(ans < now){
            ans = now;
        }
    }while(next_permutation(d.begin(), d.end()));
    cout << ans << '\n';

    return 0;
}
