#include "stdio.h"
struct MyStruct {
    int data;
};
int main(){
    // struct MyStruct obj = MyStruct();
    // 在C中，结构体的实例化不能通过等号进行初始化，C不支持直接调用默认的构造函数，而且Struct中没有成员函数
    // MyStruct obj; // 这么写也是错误的， 没有这个类型， 需要补全struct
    struct MyStruct obj;
    // 所以在结构体前面加typedef就是为了以后用到这个类型定义的时候，省些struct
    obj.data = 4;
    printf("%d", obj.data);
    return 0;
}