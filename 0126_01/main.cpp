#include <iostream>
#include <string>
#include <fstream>

const int MAX = 1e4;
using namespace std;

struct Deque{
    int data[100000] = {0,};
    int frontD, backD;
    Deque(){
        frontD = 0;
        backD = 0;
    }
    void push_front(int n){
//        cout << "push_front" << endl;
        data[frontD] = n;
        frontD = (frontD-1+MAX) % MAX;
    }
    void push_back(int n){
        backD = (backD+1) % MAX;
        data[backD] = n;
    }
    bool empty(){
        if(frontD == backD){
            return true;
        }
        else
            return false;
    }
    int size(){
        return (backD-frontD)%MAX;
    }
    int front(){
        if((backD-frontD) == 0)
            return -1;
        else{
            return data[(frontD+1)%MAX];
        }
    }
    int back(){
        if((backD-frontD) == 0)
            return -1;
        else{
            return data[backD];
        }
    }
    int pop_front(){
        if((backD-frontD) == 0)
            return -1;
        else{
            int temp = data[(frontD+1)%MAX];
            data[(frontD+1)%MAX] = 0;
            frontD = (frontD+1)%MAX;
            return temp;
        }
    }
    int pop_back(){
        if((backD-frontD) == 0)
            return -1;
        else{
            int temp = data[backD];
            data[backD] = 0;
            backD = (backD-1+MAX)%MAX;
            return temp;
        }
    }
};

int main(void){
    ifstream readFile;
    readFile.open("test2.txt");

    if(readFile.is_open()){
        while(!readFile.eof()){
//            string str;
//            getline(readFile, str);
//            cout << str << endl;
            int n;
            readFile >> n;
            Deque de;

            while(n--){
                string cmd;
                readFile >> cmd;
                if(cmd == "push_back"){
                    int pushN;
                    readFile >> pushN;
                    de.push_back(pushN);
                } else if(cmd == "push_front"){
                    int pushFrontN;
                    readFile >> pushFrontN;
                    de.push_front(pushFrontN);
                } else if(cmd == "push_back"){
                    int pushBackN;
                    readFile >> pushBackN;
                    de.push_back(pushBackN);
                } else if(cmd == "pop_front"){
//                    cout << "pop_front" << endl;
                    cout << de.pop_front() << "\n";
                } else if(cmd == "pop_back"){
//                    cout << "pop_back" << endl;
                    cout << de.pop_back() << "\n";
                } else if(cmd == "size"){
//                    cout << "size" << endl;
                    cout << de.size() << "\n";
                } else if(cmd == "empty"){
                    cout << de.empty() << "\n";
                } else if(cmd == "front"){
//                    cout << "front" << endl;
                    cout << de.front() << "\n";
                } else if(cmd == "back"){
//                    cout << "back" << endl;
                    cout << de.back() << "\n";
                }
            }

        }
        readFile.close();
    }

}