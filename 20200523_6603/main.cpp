#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while(true){
        int n;
        cin >> n;

        if(n == 0)
            break;

        vector<int> data(n);
        vector<int> check(n-6, 1);

        for(int i=0; i<6; i++){
            check.push_back(0);
        }
        sort(check.begin(), check.end());


        for(int i=0; i<n; i++){
            cin >> data[i];
        }
        sort(data.begin(), data.end());

        do{
            for(int i=0; i<check.size(); i++){
                if(check[i] == 0)
                    cout << data[i] << " ";
            }
            cout << '\n';
        }while(next_permutation(check.begin(), check.end()));
        cout << '\n';
    }
    return 0;
}
