#include <iostream>
#include <queue>

using namespace std;
int gorl[] = {-1, 1, 0, 0};
int goud[] = {0, 0, 1, -1};

int data[110][110];
int d[110][110];

int bfs(int m, int n){
    deque<pair<int,int>> q;
    q.push_back(make_pair(1,1));
    d[1][1] = 0;

    while(!q.empty()){
        int nowm = q.front().first;
        int nown = q.front().second;
//        cout << nowm << " " << nown << '\n';
        q.pop_front();

        for(int i=0; i<4; i++){
            int newm = nowm + gorl[i];
            int newn = nown + goud[i];
            if(newm < 1 || newm > m || newn < 1 || newn > n)
                continue;
            if(d[newm][newn] == -1){
                if(data[newm][newn] == 0){
                    d[newm][newn] = d[nowm][nown];
                    q.push_front(make_pair(newm, newn));
                }
                else{
                    d[newm][newn] = d[nowm][nown] + 1;
                    q.push_back(make_pair(newm, newn));
                }
            }
        }
    }

//    for(int i=1; i<=m; i++){
//        for(int j=1; j<=n; j++){
//            cout << data[i][j] << " ";
//        }
//        cout << '\n';
//    }

    return d[m][n];
}

int main() {
    int n, m;
    cin >> n >> m;
//    cout << "m: " << m << " n : " << n << '\n';

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            scanf("%1d", &data[i][j]);
            d[i][j] = -1;
        }
    }

    int ans = bfs(m, n);
    cout << ans << '\n';

    return 0;
}
