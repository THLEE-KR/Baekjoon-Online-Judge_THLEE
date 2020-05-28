#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int data[20][20];
long long minSum = INT64_MAX;
long long sum;

long long check(vector<int>& v){
    int sum = 0;

    for(int i=0; i<v.size(); i++){
        if(data[v[i]][v[(i+1) % v.size()]] == 0){
//            cout << "NO" << '\n';
            return INT64_MAX;
        }

        sum += data[v[i]][v[(i+1) % v.size()]];
    }
//    cout << "sum : " << sum << '\n';
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> data[i][j];
        }
        v[i] = i;
    }

     sort(v.begin(), v.end());

    do{
        sum = check(v);

        minSum = min(minSum, sum);

    }while(next_permutation(v.begin(), v.end()));

    cout << minSum << '\n';
    return 0;
}
