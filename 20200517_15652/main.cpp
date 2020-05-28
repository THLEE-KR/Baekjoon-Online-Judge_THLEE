#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> data;
vector<int> output(10);
vector<bool> check(10);
vector<vector<int>> fin;

void go(int index, int n, int m){
    if(index == m){
        vector<int> temp;
        for(int i=0; i<m; i++)
            temp.push_back(output[i]);
        fin.push_back(temp);
        return;
    }

    for(int i=0; i<n; i++){
//        if(check[i] == true) continue;

        if((index > 0) && (output[index-1] > data[i])) continue;
//        cout << "data[index-1] : " << data[index-1]
//        << "  i+1 : " << i+1 << '\n';

        output[index] = data[i];
//        cout << "data[i] : " << data[i] << '\n';
        check[i] = true;
//        cout << "index + 1 : " << index + 1 << '\n';
        go(index+1, n, m);
//        check[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        data.push_back(input);
    }

    sort(data.begin(), data.end());

    go(0, n, m);
    sort(fin.begin(), fin.end());
    fin.erase(unique(fin.begin(), fin.end()), fin.end());
    for(auto &v : fin){
        for(int i=0; i<m; i++){
            cout << v[i];
            if(i != m-1)
                cout << " ";
        }
        cout << '\n';
    }

    return 0;
}