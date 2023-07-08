#pragma once
#include <iostream>

class MyClass {
private:
    int data;
public:
    MyClass() = default; // 隐式构造函数
    MyClass::MyClass(){}; // 显式构造函数
    ~MyClass() = default;
};