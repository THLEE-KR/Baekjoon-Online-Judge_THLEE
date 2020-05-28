#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
//    string in_line;
//    ifstream in("test.txt");
//    while(getline(in,in_line)){
//        cout<<in_line<<endl;
//    }
//    in.close();

    string out_line;
    ofstream out("test2.txt");
    for(int i=0;i<=10;i  ){
        cin>>out_line;
        out<<out_line<<endl;
    }
    out.close();

    return 0;
}