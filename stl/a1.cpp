#include <iostream>
using namespace std;
int main(){
    int i= 32;
    int *p = &i;
    cout <<"p指向的值：" << *p << endl;
    int* &r = p;
    int j = 33;
    r = &j;
    cout <<"p指向的值： "<< *p << endl;

    return 0;
}