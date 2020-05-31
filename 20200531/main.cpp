#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int team[30][30];
int n;

int go(int index, vector<int>& first, vector<int>& second){
    if(index == n){
        if(first.size() < 1)
            return -1;
        if(second.size() < 1)
            return -1;

        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<first.size(); i++){
            for(int j=0; j<first.size(); j++){
                if(i == j)
                    continue;
                sum1 += team[first[i]][first[j]];
            }
        }
        for(int i=0; i<second.size(); i++){
            for(int j=0; j<second.size(); j++){
                if(i == j)
                    continue;
                sum2 += team[second[i]][second[j]];
            }
        }
//        cout << "sum1: " << sum1 << " sum2: " << sum2 << '\n';
        int diff = sum1 - sum2;
        if(diff < 0)
            diff = -diff;
        return diff;
    }

    int ans = -1;

    first.push_back(index);
    int t1 = go(index+1, first, second);
//    cout << "t1 : " << t1 << '\n';
    if(ans == -1 || (t1 != -1 && ans > t1))
        ans = t1;
    first.pop_back();

    second.push_back(index);
    int t2 = go(index+1, first, second);
//    cout << "t2 : " << t2 << '\n';
    if(ans == -1 || (t2 != -1 && ans > t2))
        ans = t2;
    second.pop_back();

    return ans;
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> team[i][j];
        }
    }

    vector<int> first;
    vector<int> second;
    cout << go(0, first, second) << '\n';

    return 0;
}
