#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> data(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> data[i][j];
        }
    }

    int ans = -1;
    vector<int> team(n);
    for(int i=0; i<n/2; i++){
        team[i] = 1;
    }
    sort(team.begin(), team.end());

    do{
        vector<int> first, second;
        for(int i=0; i<n; i++){
            if(team[i] == 0){
                first.push_back(i);
            }
            else{
                second.push_back(i);
            }
        }
        int one = 0;
        int two = 0;
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                if(i==j) continue;
                one += data[first[i]][first[j]];
                two += data[second[i]][second[j]];
            }
        }
        if(ans == -1 || ans > abs(one-two))
            ans = abs(one-two);
    }while(next_permutation(team.begin(), team.end()));

    cout << ans << '\n';

    return 0;
}
