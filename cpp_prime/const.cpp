#include <iostream>
using namespace std;
// const关键字指定变量的值是常量 不能进行修改
// 使用const定义的值需要接受类型检查，并可以代替常量表达式，在C++中，可以使用const变量指定数组大小
// const关键字可以在指针声明中使用









// 定义const对象
const int bufferSize = 512; // 不可被修改
// const int failInit; //错误 未初始化
// 常量在定义后不能被改变，所以必须初始化
// 类中的const成员变量必须通过初始化列表进行初始化
class A {
public:
    A() = default;
    A(int i);
    const int &r;
private:
    const int a;
    static const int b;
};
const int A::b = 10;
A::A(int i):a(i),r(a){}


// const对象默认为文件的局部变量
// 在全局作用域中定义非const变量时，它在整个程序中都可以访问。在一个文件中定义一个变量，在另一个文件中用extern就可以访问


// 与其他变量不同，除非特别声明，在全局作用域下声明的const变量是该文件的局部变量，不能被其他文件访问。如果想访问需要这么写

















// 在C++中，const修饰的是右侧的类型，即右侧的内容被视为常量。
// 如果右侧没有类型（例如指针或引用），则const修饰左侧的内容
// 当左侧和右侧都有类型时，const修饰右侧——，当右侧是指针或引用是修饰左侧，因为指针或引用不是类型
// const放在*前 后 有不同的含义
// const放在 * 前 const char* aptr表示 aptr是一个指向字符的指针，而指针所指向的字符内容是常量，即不能通过aptr修改所指向的字符
// const放在 * 后 char* const aptr表示 aptr是一个指向字符的常量指针，一旦初始化后，aptr的指向不能变，但可以通过aptr修改指向的内容
int main(){
    const int maxarray = 255;
    char store_char[maxarray]; // 在C中不行
    char a = 'a';
    char* c= &a;
    char *const aptr = c; // char指针，且是个常量指针 需要初始化。
    const char* bptr; // 指向常量char的指针，意思是bptr需要是常量，

    return 0;
}