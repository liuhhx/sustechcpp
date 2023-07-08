#pragma once
#include <iostream>

class MyTime
{
    int hours;
    int minutes;
  public:
    MyTime(): hours(0), minutes(0){}
    MyTime(int h, int m): hours(h), minutes(m){}

    // 构造函数转换
    MyTime(int m): hours(0), minutes(m) {
        this->hours += this->minutes/60;
        this->minutes%=60;
    }

    MyTime operator+(const MyTime & t) const
    {
        MyTime sum;
        sum.minutes = this->minutes + t.minutes;
        sum.hours = this->hours + t.hours;

        sum.hours +=  sum.minutes / 60;
        sum.minutes %= 60;
        
        return sum;
    }
    // 返回引用类型，避免拷贝
    MyTime & operator+=(const MyTime & t) 
    {
        this->minutes += t.minutes;
        this->hours += t.hours;

        this->hours +=  this->minutes / 60;
        this->minutes %= 60;
        
        return *this;
    }

    MyTime operator+(int m) const
    {
        MyTime sum;
        sum.minutes = this->minutes + m;
        sum.hours = this->hours;
        sum.hours +=  sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
    }

    friend MyTime operator+(int m, const MyTime & t)
    {
        // 这里的做法非常巧妙，一个int类型的数加上一个MyTime类型的数
        // 调换位置可以用之前定义的+重载
        return t + m;
    }
    // 括号后面的const表示这是一个成员函数，并且告诉编译器，这个函数在执行过程中不会修改任何成员变量的值
    std::string getTime() const
    {
        return std::to_string(this->hours) + " hours and " 
                + std::to_string(this->minutes) + " minutes.";
    }

    friend std::ostream & operator<<(std::ostream & os, const MyTime & t)
    {
        std::string str = std::to_string(t.hours) + " hours and " 
                        + std::to_string(t.minutes) + " minutes.";
        os << str;
        return os;
    }
    friend std::istream & operator>>(std::istream & is, MyTime & t)
    {
        is >> t.hours >> t.minutes;
        t.hours +=  t.minutes / 60;
        t.minutes %= 60;
        return is;
    }
    // 类型转换
    // 用户自定义类型转换
    // 1.可以写操作符(类型符)重载转换
    // 2.可以使用构造函数转换
    // 3.可以使用等号重载转换
    // 隐式转换
    operator int() const{
        return this->hours*60 + this->minutes;
    }

    // 显式转变
    // 这个也可以隐式转换，但是是去找上一个函数了，先转成int 再从int转float，但是这一定不是开发者想看到的结果，所以隐式转换很危险
    explicit operator float() const{
        return float(this->hours*60 + this->minutes);
    }

    MyTime & operator=(int m){
        this->hours = 0;
        this->minutes = m;
        this->hours = this->minutes/60;
        this->minutes%=60;
        return *this;
    }

    /*
        这个重载在下面生效
    
        MyTime t3; // 执行构造函数
        MyTime t4 = 80; // 这里也是构造函数 不会重载等号
        t3 = 80; // 这才生效。实例化的时候不会重载
    */


    // 自增自减重载
    // prefix increment
    MyTime& operator++(){
        this->minutes++;
        this->hours+=this->minutes/60;
        this->minutes = this->minutes%60;
        return *this;
    }
    // postfix
    MyTime operator++(int){
        MyTime old = *this;
        operator++();
        return old;
    }
    // 从这段代码可以看出，后缀自增(values++)，会先拷贝一份对象，在元素的基础上做++
    // 从编译器优化的角度来看，后缀自增操作符可能会引入额外的性能开销。由于需要创建原始对象的副本，会涉及到对象的复制构造函数或移动构造函数的调用，以及额外的内存分配和拷贝操作。
    // 但对于大多数情况而言，编译器会对代码做是适当的优化，使用前缀还是后缀的差异并不是很大

    // 后缀自增也不是一无是处，主要用途是语法一致性，迭代器操作，表达式求值等等
    
};

