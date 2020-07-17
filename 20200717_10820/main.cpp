#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str;
    while(getline(cin, str)){
//        cout << "str: " << str << '\n';
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;

        for(int i=0; i<str.length(); i++){
            if(str[i] >= 'a' && str[i] <= 'z')
                lower += 1;
            else if(str[i] >= 'A' && str[i] <= 'Z')
                upper += 1;
            else if(str[i] >= '0' && str[i] <= '9')
                number += 1;
            else
                space += 1;
        }

        cout << lower << " " << upper << " " <<
        number << " " << space << '\n';
    }



    return 0;
}
