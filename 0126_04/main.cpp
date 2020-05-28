#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

int main(void){
    ifstream readFile;
    readFile.open("test.txt");

    if(readFile.is_open()){
        while(!readFile.eof()){
//            string str;
//            getline(readFile, str);
//            cout << str << endl;
            string str;
//            readFile >> n;
            getline(readFile, str);
            int size_c = str.size();

            bool flag = false;
            bool flag2 = false;
            int pr = 0;
            stack<char> s;
            for(int i=0; i<size_c; i++){
                if(str[i] == '('){
                    s.push(str[i]);
                    flag = false;
                    flag2 = false;
                }
                else{
                    if(flag)
                        flag2 = true;
                    flag = true;

                    s.pop();
//                    cout<< s.size() << endl;
                    if(!flag2)
                        pr += s.size();
                    else{
                        cout << "++" << endl;
                        pr++;
                        cout << pr << endl;
                    }

                    cout << pr << endl;

                }
            }
            cout << pr << endl;
        }
        readFile.close();
    }
    return 0;
}