#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> input(n+10);
    for(int i=1; i<=n; i++){
        cin >> input[i];
    }

    vector<int> result(n+10);
    result[1] = input[1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
//            cout << "result" << i << " : " << result[i] <<
//            " result" << i-j << " : " << result[i-j] <<
//            " input" << j << " : " << input[j] << '\n';
            if(result[i] > result[i-j] + input[j] || result[i] == 0)
                result[i] = result[i-j] + input[j];
        }
    }
    cout << result[n] << '\n';

    return 0;
}
