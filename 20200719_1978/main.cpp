#include <iostream>
using namespace std;

int sosu(int input){
    if(input == 1)
        return 0;
    for(int i=2; i*i<=input; i++){
        if(input%i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    while(n--){
        int input;
        cin >> input;
        cnt += sosu(input);
    }
    cout << cnt << '\n';

    return 0;
}