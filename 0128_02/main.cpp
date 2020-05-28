#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#define SIZE 100000

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
            int data1[SIZE], data2[SIZE];
            readFile >> n1 >> n2;

            for(int i=0; i<n1; i++){
                readFile >> data1[i];
                data2[i] = abs(n2 - data1[i]);
//                printf("%d\n", data2[i]);
            }

            int answer = 0;
//            printf("%d\n", answer);
            for(int i=0; i<n1; i++){
                for(int j=i+1; j<n1; j++){
                    int temp = GCD(data2[i], data2[j]);
                    if(answer != 0)
                        answer = min(answer, temp);
                    else
                        answer = temp;
//                    printf("%d\n", answer);
                }
            }
            printf("%d\n", answer);

        }
        readFile.close();
    }
    return 0;
}