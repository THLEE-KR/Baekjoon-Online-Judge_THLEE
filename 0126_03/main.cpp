#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void){
    ifstream readFile;
    readFile.open("test2.txt");

    if(readFile.is_open()){
        while(!readFile.eof()){
//            string str;
//            getline(readFile, str);
//            cout << str << endl;
            char n[100000];
//            readFile >> n;
            readFile.getline(n, 100000);
            cout << n << endl;

        }
        readFile.close();
    }
}