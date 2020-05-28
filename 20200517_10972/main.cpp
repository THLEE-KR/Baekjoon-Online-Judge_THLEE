#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int end = n-1;
    int i = 0;
    while((end > 0) && (v[end-1] >= v[end]))
        end--;
    if(end == 0){
        cout << "-1" << '\n';
        return 0;
    }
    else
        i = end;
//    cout << "i : " << i << endl;

    end = n-1;
    int j = 0;
    while((end >= i) && (v[end] <= v[i-1]))
        end--;
    if(end < i){
        cout << "-1" << '\n';
        return 0;
    }
    else
        j = end;
//    cout << "j : " << j << endl;

    swap(v[i-1], v[j]);
//    for(auto e:v)
//        cout << e << " ";
//    cout << '\n';

    end = n-1;
    while(i < end){
        swap(v[i], v[end]);
        i++;
        end--;
    }
    for(auto e:v)
        cout << e << " ";
    cout << '\n';

    return 0;
}
