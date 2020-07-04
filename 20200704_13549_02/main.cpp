#include <iostream>
#include <deque>
#define MAX 200000
using namespace std;

bool check[MAX + 10];
int d[MAX + 10];

void Solve(int now, int target){
    check[now] = true;
    d[now] = 0;
    deque<int> deq;
    deq.push_back(now);

    while(!deq.empty()){
        int nnow = deq.front();
//        cout << "nnow: " << nnow << '\n';
        deq.pop_front();
        if(nnow*2 < MAX){
            if(check[nnow*2] == false){
                deq.push_front(nnow*2);
                check[nnow*2] = true;
                d[nnow*2] = d[nnow];
            }
        }
        if(nnow-1 >= 0){
            if(check[nnow-1] == false){
                deq.push_back(nnow-1);
                check[nnow-1] = true;
                d[nnow-1] = d[nnow] + 1;
            }
        }
        if(nnow+1 < MAX){
            if(check[nnow+1] == false){
                deq.push_back(nnow+1);
                check[nnow+1] = true;
                d[nnow+1] = d[nnow] + 1;
            }
        }
    }
}

int main() {
    int now, target;
    cin >> now >> target;

    Solve(now, target);
    cout << d[target];
    return 0;
}
