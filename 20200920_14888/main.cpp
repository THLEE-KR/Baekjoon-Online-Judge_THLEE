#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(const vector<int> &num, const vector<int> &op){
    int answer = num[0];
    for(int i=0; i<op.size(); i++){
//        cout << "op: " << op[i] << '\n';
        if(op[i] == 0){
            answer += num[i+1];
        }
        else if(op[i] == 1){
            answer -= num[i+1];
        }
        else if(op[i] == 2){
            answer *= num[i+1];
        }
        else{
            answer /= num[i+1];
        }
    }
//    cout << "answer : " << answer << '\n';
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    vector<int> op;
    for(int i=0; i<4; i++){
        int cnt;
        cin >> cnt;
        while(cnt--){
            op.push_back(i);
        }
    }
//    cout << "len: " << op.size() << '\n';

    vector<int> ans;
    do{
        ans.push_back(check(num, op));
    }while(next_permutation(op.begin(), op.end()));

    cout << *minmax_element(ans.begin(), ans.end()).second << '\n';
    cout << *minmax_element(ans.begin(), ans.end()).first << '\n';

    return 0;
}
