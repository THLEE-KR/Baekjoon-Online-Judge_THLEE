#include <iostream>
#include <algorithm>

using namespace std;

bool check(const int* data, const int i, const int j){
    int sum = 0;
    for(int a=0; a<9; a++){
        sum += data[a];
    }

    sum -= (data[i] + data[j]);

    if(sum == 100)
        return true;
    else
        return false;
}

int main() {
    int data[9];

    for(int i=0; i<9; i++){
        cin >> data[i];
    }

    sort(data, data+9);

//    for(int i=0; i<9; i++){
//        cout << data[i] << '\n';
//    }

    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(check(data, i, j)){
                data[i] = 0;
                data[j] = 0;
                break;
            }
            else
                continue;
        }
    }

    for(int i=0; i<9; i++){
        if(data[i] != 0)
            cout << data[i] << '\n';
    }

    return 0;
}
