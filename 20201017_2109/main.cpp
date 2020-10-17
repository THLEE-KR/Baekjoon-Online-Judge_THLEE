#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct lecture{
    int p;
    int d;
};

int main() {
    int n;
    cin >> n;
    vector<lecture> lec(n);

    for (int i = 0; i < n; ++i) {
        cin >> lec[i].p >> lec[i].d;
    }

    sort(lec.begin(), lec.end(), [](lecture &a, lecture & b)
    {
        return a.d > b.d;
    });

//    for(int i=0; i<lec.size(); i++){
//        cout << lec[i].p << " ";
//    }
//    cout << '\n';

    int k = 0;
    priority_queue<int> q;
    int ans = 0;
    for(int i=10000; i>=1; i--){
        while(k<n && lec[k].d == i){
            q.push(lec[k].p);
            k += 1;
        }
        if(q.empty() == false){
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}
