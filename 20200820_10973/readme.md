##### CHECK
- 등호 주의
- j = n-1; 초기화

```C++
if (prev_permutation(a.begin(),a.end())) {
        for (int i=0; i<n; i++) {
            cout << a[i] << ' ';
        }
    } 
else {
        cout << "-1";
    }
```