#include <iostream>
using namespace std;

// 在函数中声明变量时，static将指定变量 在 对该函数的调用中保持其状态
void showcast(int curr) {
    static int n;
    n+=curr;
    cout << "n is " << n << endl;
}
void showstat(int curr){
    int n=0;
    n+=curr;
    cout << "n is " << n << endl;
}
// 在类声明中声明成员函数时，static 关键字将指定类的所有实例共享该函数。 
// 由于函数没有隐式 this 指针，因此 static 成员函数不能访问实例成员。 
// 若要访问实例成员，请使用作为实例指针或引用的参数来声明函数。

class Myclass{
public:
    int instanceVariable = 0;
    static void staticFunction(){
        // cout << instanceVariable << endl; // 无法访问实例成员变量
    }
    static void staticFunction(Myclass& cls){
        cout << cls.instanceVariable << endl; // 可以访问
    }
};




int main(){
    // for(int i=0;i<5;++i){
    //     // showcast(i);
    //     showstat(i);
    // }
    Myclass s;
    Myclass::staticFunction(s);
    return 0;
}

