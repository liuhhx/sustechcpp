// 在函数前加inline修饰符，只是建议编译器把这个函数做成inline的形式，如果函数体过大可能编译器不会做成inline

#include <iostream>
#define MAX_MACRO(a,b)(a)>(b)?(a):(b)
using namespace std;
inline float max_func(float a1, float a2){
    return a1>a2?a1:a2;
}
int main(){
    float a1 = 1.0;
    float a2 = 1.01;
    cout << "The max value is " << max_func(a1,a2) << "between a1 and a2" <<endl;

    int num1 = 20;
    int num2 = 30;
    int maxv = MAX_MACRO(num1++,num2++);
    cout << "max value is " << maxv<<endl;
    cout << "猜猜num2的值是多少？"<< num2<<endl;
    // inline相当于直接把函数体嵌进来，减少压栈的开销等等
    return 0;
}



// 思考：这么简单的函数为什么不用宏 macros
// 宏很同意错误
