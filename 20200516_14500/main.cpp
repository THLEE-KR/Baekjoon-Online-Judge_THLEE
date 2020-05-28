#include <iostream>
#include <vector>

using namespace std;

int go(const int& a, const int& b, int x, int y){


    for(int i=x; i<=a*b; i+=a){
        if((i-1)%a == (x-1)%a &&
                (i-1)%b == (y-1)%b)
            return i;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> fin;

    for(int i=0; i<n; i++){
        int a,b, x, y;
        cin >> a >> b >> x >> y;

        int ans = go(a, b, x, y);
//        cout << ans << '\n';
        fin.push_back(ans);
    }

    for(int i=0; i<fin.size(); i++){
        cout << fin[i] << '\n';
    }

    return 0;
}
