#include<iostream>
using namespace std;
// 操作符重载
// 你可以在全局或为各个类重新定义大多数内置运算符的函数。 重载运算符作为函数来实现。
struct Complex {
    Complex(double r, double i):re(r), im(i){}
    Complex operator+(Complex& other){
        return Complex(re+other.re, im+other.im);
    }
    void Display(){cout << re<<", "<<im << endl;}
private:
    double re, im;
};

// Complex Complex::operator+(Complex& other){
//     return Complex(re+other.re, im+other.im);
// }

class Complexx {
private:
    double re, im;
public:
    Complexx(double r, double i):re(r),im(i){}
    Complexx operator+(Complexx& other);
    friend Complexx operator+(const Complexx&c1, const Complexx&c2);
    void Display(){cout << re<<", " <<im<<endl;}
};
// Complexx Complexx::operator+(Complexx& other){
//     return Complexx(re+other.re, im+other.im);
// }
// Complexx operator+(const Complexx&c1,const Complexx&c2){
//     double r = c1.re+c2.re;
//     double i = 
// }
// 友元：类可以允许其他类或者函数访问它的私有成员变量，方法是令其他类或者函数成为类的友元
// 在函数或类前声明`friend`

int main(){
    Complex a = Complex(1.2, 3.4);
    Complex* b = new Complex(6,8);
    Complex c = Complex(0,0);

    c = a+*b;
    // c.Display();

    Complexx * t1 = new Complexx(1,2);
    Complexx * t2 = new Complexx(3,4);
    Complexx res = Complexx(0,0);
    res = *t1 + * t2;
    res.Display();
    return 0;
}

// 自增和自减操作重载 ，这是单目的重载

