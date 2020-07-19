#include <iostream>
using namespace std;
#define MAX 1000010
bool data[MAX];

void sosu(){
    for(int i=2; i*i<MAX; i++){
        if(data[i] == true)
            continue;
        for(int j=2; i*j<MAX; j++){
            data[i*j] = true;
        }
    }
}

void print_sosu(int a, int b){
    for(int i=a; i<=b; i++){
        if(data[i] == false)
            cout << i << '\n';
    }
}

int main() {
    int a,b;
    cin >> a >> b;

    sosu();
    print_sosu(a,b);

    return 0;
}
