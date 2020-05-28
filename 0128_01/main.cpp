#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

int GCD(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void){
    ifstream readFile;
    readFile.open("test.txt");

    if(readFile.is_open()){
        while(!readFile.eof()){
//            string str;
//            getline(readFile, str);

            int n1, n2;
            int dataAry[101];
            readFile >> n1;

            int answer = 0;

            while(n1--){
                answer = 0;
                readFile >> n2;
                for(int i=0; i<n2; i++){
                    readFile >> dataAry[i];
                }
                for(int i=0; i<n2; i++){
                    for(int j=i+1; j<n2; j++){
                        answer += GCD(dataAry[i], dataAry[j]);
                    }
                }
                printf("%d\n", answer);
            }

        }
        readFile.close();
    }
    return 0;
}