#include <iostream>
#include <vector>
using namespace std;
void change(vector<int> &a, int index){
    for(int i=index-1; i<=index+1; i++){
        if(0 <= i && i < a.size()){
            a[i] = 1-a[i];
        }
    }
}

pair<bool, int> go(vector<int> a, vector<int> &goal) {
    int n = a.size();
    int ans = 0;
    for (int i=0; i<n-1; i++) {
        if (a[i] != goal[i]) {
            change(a, i+1);
            ans += 1;
        }
    }
    if (a == goal) {
        return make_pair(true, ans);
    } else {
        return make_pair(false, ans);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++){
        scanf("%1d", &a[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%1d", &b[i]);
    }

    auto p1 = go(a, b);

    change(a, 0);
    auto p2 = go(a, b);
    if(p2.first){
        p2.second += 1;
    }


    if(p1.first == true && p2.first == true){
        cout << min(p1.second, p2.second);
    }
    else if(p1.first == true){
        cout << p1.second;
    }
    else if(p2.first == true){
        cout << p2.second;
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}
