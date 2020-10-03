#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m;
bool alphabet[30];
int goA[] = {0, 0, 1, -1};
int goB[] = {1, -1, 0, 0};

int go(const vector<string> &d, const int i, const int j){
    int ans = 0;
    for(int k=0; k<4; k++){
        int ni = i + goA[k];
        int nj = j + goB[k];

        if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if(alphabet[d[ni][nj]-'A'] == true) continue;

        alphabet[d[ni][nj]-'A'] = true;
        int temp = go(d, ni, nj);
        if(ans < temp){
            ans  = temp;
        }
        alphabet[d[ni][nj]-'A'] = false;
    }

    return ans + 1;
}

int main() {
    cin >> n >> m;
    vector<string> d(n);
    for(int i=0; i<n; i++){
        cin >> d[i];
    }

    alphabet[d[0][0]-'A'] = true;
    int ans = go(d, 0, 0);
    cout << ans << '\n';

    return 0;
}
