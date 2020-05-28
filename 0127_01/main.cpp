#include <iostream>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    if(n == 0)
        printf("0");
    else if(n == 1)
        printf("1");
    int ans = 1;
    for(int i=2; i<=n; i++){
        ans *= i;
    }
    printf("%d", ans);
}