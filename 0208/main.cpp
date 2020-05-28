#include <iostream>
using namespace std;

int main(void){
    int n1;
    scanf("%d", &n1);
    int ary[1010];
    int ans[1010];
    for(int i=0; i<n1; i++){
        scanf("%d", &ary[i]);
    }

    for(int i=0; i<n1; i++){
        ans[i] = 1;
        for(int j=0; j<i; j++){
            if(ary[j] < ary[i] && ans[i] < ans[j]+1)
                ans[i] = ans[j]+1;
        }
    }

    printf("%d", ans[n1-1]);
}