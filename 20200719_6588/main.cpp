#include <iostream>
using namespace std;
#define MAX 1000010
bool data[MAX];
int prime[MAX];
int pn;

void sosu(){
    data[0] = data[1] = true;
    for(int i=2; i*i<MAX; i++){
        if(data[i] == true)
            continue;
        prime[pn++] = i;
        for(int j=2; i*j<MAX; j++){
            data[i*j] = true;
        }
    }
}

void solve(int input){
    for(int i=1; i<pn; i++){
        if(!data[input-prime[i]] && !data[prime[i]]){
            cout << input << " = " << prime[i] << " + " << input-prime[i] << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sosu();
    while(true){
        int input;
        cin >> input;
        if(input == 0)
            break;
        solve(input);
    }

    return 0;
}
