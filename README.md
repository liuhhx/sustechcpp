# sustechcpp
南方科技大学cpp课程

声明放在头文件h hpp
实现放在cpp
增加可读性、易于管理

当有多个cpp文件时，可以分开编译 也可以一起编译
```shell
g++ main.cpp mul.cpp -o outs
```
当文件很多的时候，一起编译很浪费时间

错误：
    编译错误 一般由语法造成
    链接错误 链接时报错 undefined symbols
    运行时错误 溢出等等

预处理和宏：
    预处理在编译之前运行
    预处理指令以#号开头 每个预处理执行占一行 只能一行
    宏只是**替换**

如何通过命令行和程序交互
    使用命令行参数交互
    ```clike
    // argc是参数的个数
    // argv是各个参数 二维字符串数组
    int main(int argc, char *argv[]);
    int main(int argc, char **argv);
    ```

整数 integer
    char type of character, 8-bit integer indeed!
    signed char:
    unsigned char:
    char: either signed char or unsigned char
bool
    c++关键字 不是c
    长度1字节 不是1位


float:

how many numbers in range [0,1]?
**infinite!**
how many numbers can 32 bits represent?
2^32

只能在0-1采样取一些代表性的点 来表示一些实数
如果想表示1.2 float提供的是1.200000047683716

Are computers always accurate? No
Floating-point operations always bring some tiny errors.
Those errors cannot be eliminated.
What can we do: to manage them not to cause a problem.


float数值比较相等
```c++
if(fabs(f1 -f2) < FLT_EPSILON) // GOOD
```

inf(exponent = 11111111, fraction = 0)
nan(exponent = 11111111, fraction != 0)