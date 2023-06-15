#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float f1 = 2.0f/0.0f;
    float f2 = 0.0f/0.0f;
    cout << f1 << endl; // inf
    cout << f2 << endl; // nan
    return 0;
}