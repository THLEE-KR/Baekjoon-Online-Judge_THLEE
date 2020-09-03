#include <iostream>
#include <deque>
using namespace std;
#define MAX 200000
bool check[MAX + 10];
int d[MAX + 10];

void bfs(int start, int end){
    check[start] = true;
    d[start] = 0;
    deque<int> deq;
    deq.push_back(start);

    while(!deq.empty()){
        int n = deq.front();
        deq.pop_front();

        if(2*n <= MAX && check[2*n] == false){
            deq.push_front(2*n);
            check[2*n] = true;
            d[2*n] = d[n];
        }

        if(n+1 <= MAX && check[n+1] == false){
            deq.push_back(n+1);
            check[n+1] = true;
            d[n+1] = d[n] + 1;
        }
        if(n-1 >= 0 && check[n-1] == false){
            deq.push_back(n-1);
            check[n-1] = true;
            d[n-1] = d[n] + 1;
        }
    }

    cout << d[end] << '\n';
}

int main() {
    int start, end;
    cin >> start >> end;
    bfs(start, end);

    return 0;
}
