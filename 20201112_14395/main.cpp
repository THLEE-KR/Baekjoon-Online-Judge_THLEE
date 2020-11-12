#include <iostream>
#include <set>
#include <tuple>
#include <string>
#include <queue>
using namespace std;
const long long limit = 1000000000LL;
void calculate(const long long s, const long long t)
{
    set<long long> check;
    queue<pair<long long, string>> q;
    q.push(make_pair(s, ""));
    check.insert(s);
    while(q.empty() == false)
    {
        long long x;
        string str;
        tie(x, str) = q.front(); q.pop();
//        cout << x << str << '\n';
        if(x == t)
        {
            if(str.length() == 0)
            {
                str = "0";
            }
            cout << str << '\n';
            return;
        }
        if(0 <= x*x && x*x <= limit && check.count(x*x) == 0)
        {
            q.push(make_pair(x*x, str+"*"));
            check.insert(x*x);
        }
        if(0 <= x+x && x+x <= limit && check.count(x+x) == 0)
        {
            q.push(make_pair(x+x, str+"+"));
            check.insert(x+x);
        }
        if(0 <= x-x && x-x <= limit && check.count(x-x) == 0)
        {
            q.push(make_pair(x-x, str+"-"));
            check.insert(x-x);
        }
        if(x != 0 && 0 <= x/x && x/x <= limit && check.count(x/x) == 0)
        {
            q.push(make_pair(x/x, str+"/"));
            check.insert(x/x);
        }
    }
    cout << -1 << '\n';
    return;
}

int main() {
    long long s, t;
    cin >> s >> t;
    calculate(s, t);

    return 0;
}
