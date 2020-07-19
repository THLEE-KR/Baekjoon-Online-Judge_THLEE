#### CHECK

- 시간초과 주의

``` c++
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
```

``` c++
for(int i=2; i<=MAX; i++){
        if(check[i] == false){
            # 소수 위치를 배열에 저장
            prime[pn++] = i;
            for(int j=i+i; j <= MAX; j+=i){
                check[j] = true;
            }
        }
    }
```