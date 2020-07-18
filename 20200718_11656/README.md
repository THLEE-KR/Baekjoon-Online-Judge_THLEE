#### check

- 문자열의 부분문자열은 substr을 이용해 구할 수 있다.

``` c++ 
basic_string substr(size_type pos = 0, size_type count = npos) const;
```
``` c++ 
std::string a = "0123456789abcdefghij";
// count 가 npos 이므로 pos 부터 문자열 끝까지 리턴한다.
std::string sub1 = a.substr(10);
// pos 와 pos + count 모두 문자열 범위 안이므로, 해당하는 부분 문자열을
// 리턴한다.
std::string sub2 = a.substr(5, 3);
// pos 는 문자열 범위 안이지만, pos+count 는 밖이므로, pos 부터 문자열 끝까지
// 리턴한다.
std::string sub4 = a.substr(a.size() - 3, 50);
```
> abcdefghij
  
>567
  
>hij