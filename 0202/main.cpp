#include <iostream>
using namespace std;

int main(void){
    int d[100][10] = {0,};
    d[1][1] = 1;

    int n1;
    scanf("%d", &n1);
    for(int i=2; i<=n1; i++){
        d[i][1] = d[i-1][0];
        d[i][0] = d[i-1][0] + d[i-1][1];
    }
    printf("%d", d[n1][0] + d[n1][1]);
    return 0;
}