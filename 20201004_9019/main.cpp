#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
bool check[10001];
int dist[10001];
int from[10001];
char how[10001];

void print(const int input, const int output){
    if(input == output) return;
    print(input, from[output]);
    cout << how[output];
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        int input, output;
        cin >> input >> output;

        memset(check, false, sizeof(check));
        memset(dist, 0, sizeof(dist));
        memset(how, 0, sizeof(how));
        memset(from, 0, sizeof(from));
        check[input] = true;
        dist[input] = 0;
        from[input] = -1;

        queue<int> q;
        q.push(input);

        while (q.empty() == false) {
            int now = q.front();
//            cout << "now: " << now << '\n';
            q.pop();

            int next = (now*2) % 10000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'D';
            }

            next = now-1;
            if (next == -1) next = 9999;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now]+1;
                from[next] = now;
                how[next] = 'S';
            }

            next = (now % 1000) * 10 + now / 1000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'L';
            }

            next = (now / 10) + (now % 10) * 1000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'R';
            }
        }
        print(input, output);
        cout << '\n';
    }
    return 0;
}
