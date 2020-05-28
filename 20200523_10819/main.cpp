#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> data;
int maxSum, sum;

int check(vector<int>& data, int& a, int& b){
    // abs가 있음!!!
    int diff = data[a] - data[b];
//    cout << "diff : " << diff << '\n';
    if(diff < 0)
        return -diff;
    else
        return diff;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        int d;
        cin >> d;
        data.push_back(d);
        v[i] = i;
    }

        // sort(v.begin(), b.end())!!!!
//    cout << "v[0] : " << v[0] << "v[1] : " << v[1] << '\n';

    do{
        int a, b;
        sum = 0;

        for(int i=0; i<n-1; i++){
            a = v[i];
            b = v[i+1];
//            cout << "a : " << a << " b : " << b << '\n';
            sum += check(data, a, b);
//            cout << check(data, a, b) << '\n';
        }
//        cout << sum << '\n';

        // maxSum = max(maxSum, sum)
        if(maxSum < sum){
            maxSum = sum;
        }

    }while(next_permutation(v.begin(), v.end()));

    cout << maxSum << '\n';
    return 0;
}
