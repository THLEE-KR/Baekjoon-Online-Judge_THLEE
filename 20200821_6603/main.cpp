#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while(1){
        int n;
        cin >> n;
        if(n == 0)
            break;

        vector<int> v(n);
        vector<int> vPerm;
        for(int i=0; i<n; i++)
            cin >> v[i];
        for(int i=0; i<6; i++)
            vPerm.push_back(0);
        for(int i=0; i<n-6; i++)
            vPerm.push_back(1);

        do{
            vector<int> ans;
            for(int i=0; i<n; i++){
                if(vPerm[i] == 0)
                    ans.push_back(v[i]);
            }

            for(int i=0; i<6; i++){
                cout << ans[i] << ' ';
            }
            cout << '\n';

        }while(next_permutation(vPerm.begin(), vPerm.end()));
        cout << '\n';
    }


    return 0;
}
