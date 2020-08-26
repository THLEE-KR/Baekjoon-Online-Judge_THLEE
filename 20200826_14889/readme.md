##### CHECK
- go(index, first, second)
    - index번째 사람을 어떤 팀에 넣을지 결정해야 함
- minValue 구할 때,
```c++
int ans = -1;
...
int t1 = go(index+1, first, second); 
if(ans == -1 || (t2 != -1 && ans > t2)){
        ans = t2;
    }
```