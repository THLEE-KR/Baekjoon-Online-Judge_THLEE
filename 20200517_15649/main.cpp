#include <iostream>
#include <vector>

using namespace std;

vector<int> data(10);
vector<bool> check(10);

void go(int index, int n, int m){
    if(index == m){
//        cout << "check!" << '\n';
        for(int i=0; i<m; i++)
            cout << data[i] << " ";
        cout << '\n';
    }

    for(int i=0; i<n; i++){
//        cout << "check[i+1] : " << check[i+1] << '\n';
        if(check[i+1] == true) continue;

        data[index] = i+1;
        check[i+1] = true;
//        cout << "index + 1 : " << index + 1 << '\n';
        go(index+1, n, m);
        check[i+1] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    go(0, n, m);

    return 0;
}
