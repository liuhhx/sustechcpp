#include <iostream>
#include "time.hpp"


// 友元：可以访问类的private成员和protected成员
/*
friend 设计的初衷是为了提供更灵活的访问控制权限，
在某些情况下，类的成员函数可能无法满足特定的需求，或者需要与类紧密协作的函数可能不适合作为类的成员函数。
此时，使用 friend 函数可以实现对类的私有成员的访问，同时保持类的封装性。

使用场景：
1. 操作符重载
    在运算符重载的实现中，有时需要直接访问类的私有成员来实现特定的操作。通过将重载的函数声明为友元函数，可以实现对私有成员的访问。
    比如重载 std::cout <<
*/


using namespace std;

int main()
{
    MyTime t1(2, 40);
    std::cout << (30 + t1).getTime() << std::endl;

    std::cout << t1 << std::endl;
    std::string a = "Fdsfsd";
    std::cout << a << std::endl;
    std::cout << "Please input two integers:" << std::endl;
    std::cin >> t1;
    std::cout << t1 << std::endl;
    return 0;
}
