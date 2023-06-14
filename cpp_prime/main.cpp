#include <bits/stdc++.h>
using namespace std;
int main(){
    // 关键字 nullptr 指定类型 std::nullptr_t 的 null 指针常量，该类型可转换为任何原始指针类型。
    auto node = nullptr;

    // C++程序由各种实体组成，例如变量、函数、命名空间等等。必须先声明才能使用

    extern int i; // 这是声明 不是定义

    // 在早期的c++版本中，typedef用于声明一个新名称，该名称是一个名称的新名称。例如：std::string就是std::basic_string<char>的别称
    // 新c++使用using来替代typedef，思路是相同的，为已声明并定义的实体声明一个别称
    using ll = long long;
    ll c=12212;
    
    // class 和 struct
    // 在cpp中这两个是相同的，只不过class默认是private，struct默认是public
    return 0;
}