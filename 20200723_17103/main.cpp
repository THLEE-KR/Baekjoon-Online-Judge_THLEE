#include <iostream>
#define MAX 1000010
using namespace std;
bool non_sosu[MAX];

int check(int input){
    int cnt = 0;
    for(int i=2; i<=input/2; i++){
       if(!non_sosu[i] && !non_sosu[input-i])
           cnt++;
    }
    return cnt;
}

int main() {
    non_sosu[0] = non_sosu[1] = true;
    for(int i=2; i*i<MAX; i++){
        for(int j=2; i*j<MAX; j++){
            non_sosu[i*j] = true;
        }
    }

    int n;
    cin >> n;
    while(n--){
        int input;
        cin >> input;
        int ans = check(input);
        cout << ans << '\n';
    }

    return 0;
}
