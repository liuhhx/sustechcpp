#include <iostream>
using namespace std;
int main(){
    int i =0;
    short s = 0;
    cout << sizeof(int) << endl;
    cout << sizeof(i) << endl;
    cout << sizeof(s) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(size_t) << endl;
    // sizeof 并不是是个函数 而是一个operator
    return 0;
}   