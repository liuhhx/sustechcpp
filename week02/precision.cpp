#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float f1 = 2.34E10f;
    float f2 = f1 + 10;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f1 - f2 = "<< f1 - f2 << endl;
    cout << "(f1 - f2) = " << (f1-f2==0) << endl;
    // outs: 相等
    // 原因是采样问题，+10大概率是原来的值
    return 0;
    // 那怎么比较两个float的值呢
    // 用 fabs 和 FLT_EPSILON 去比较 如果小 一般认定是相等
}