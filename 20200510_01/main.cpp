#include <iostream>
#include <vector>

using namespace std;

int main() {

    int E = 15;
    int S = 28;
    int M = 19;

    vector<int> input;
    for(int i=0; i<3; i++){
        int n;
        cin >> n;
        input.push_back(n);
    }
//    cout << E*S*M << '\n';
    for(int i=1; i<=E*S*M; i++){
        if(((i-1)%E) == input[0]-1
        && ((i-1)%S) == input[1]-1
        && ((i-1)%M) == input[2]-1){
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
