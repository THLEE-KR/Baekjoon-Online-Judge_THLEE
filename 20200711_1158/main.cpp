#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }

    int cnt = 0;
    cout << '<';
    while(!q.empty()){
        cnt++;
        if(cnt % k != 0)
            q.push(q.front());

        else{
            cout << q.front();
            if(q.size() != 1)
                cout << ", ";
        }

        q.pop();
    }
    cout << '>' << '\n';



    return 0;
}
