#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int data[110][110];

int go(int index, vector<int> first, vector<int> second){
    if(index == n){
        if(first.size() <= 1 || second.size() <= 1)
            return -1;

        int diff;
        int t1 = 0;
        int t2 = 0;
        for(int i=0; i<first.size(); i++){
            for(int j=0; j<first.size(); j++){
                if(i == j) continue;
                t1 += data[first[i]][first[j]];
            }
        }
        for(int i=0; i<second.size(); i++){
            for(int j=0; j<second.size(); j++){
                if(i == j) continue;
                t2 += data[second[i]][second[j]];
            }
        }
        diff = abs(t1-t2);
        return diff;
    }

    int ans = -1;
    first.push_back(index);
    int t1 = go(index+1, first, second);
    if(ans == -1 || (t1 != -1 && ans > t1))
        ans = t1;
    first.pop_back();
    second.push_back(index);
    int t2 = go(index+1, first, second);
    if(ans == -1 || (t2 != -1 && ans > t2))
        ans = t2;
    second.pop_back();
    return ans;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> data[i][j];
        }
    }

    vector<int> first, second;
    cout << go(0, first, second);
    return 0;
}
