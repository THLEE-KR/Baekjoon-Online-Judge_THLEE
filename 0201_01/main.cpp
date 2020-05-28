#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n1;
    scanf("%d", &n1);

    int d[1010];
    d[0] = 0;
    int ans[1010];
    for(int i=1; i<=n1; i++){
        scanf("%d", &d[i]);
    }
    int tmpMax = 0;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=i; j++){
            tmpMax = max(tmpMax, ans[i-j] + d[j]);
//            printf("tmpMax: %d\n", tmpMax);
            ans[i] = tmpMax;
        }
//        printf("%d\n", ans[i]);
    }
    printf("%d", ans[n1]);

    return 0;
}