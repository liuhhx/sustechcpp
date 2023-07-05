#include <iostream>
using namespace std;
// 派生类对父类中的纯虚函数进行具体的实现通常称为"实现"，而对虚函数进行具体的实现通常称为"重写"。
class Shape {
protected: // 限定介于private和public之间，允许派生类访问数据
    double area;
public:
    virtual double getArea()=0; // 纯虚函数，如果派生类没有实现父类中的纯虚函数，那么派生类就是个抽象类

};
class Circle: public Shape {
private:
    double radius;
public:
    Circle(double r):radius(r){}
    double getArea()override{
        area = 3.14*radius*radius;
        return area;
    }
};

class A{
public:
    void func(int a){
        cout << a << endl;
    }
    void funv(int a,int b){
        cout << " this is funv in A class" << endl;
        cout << a << " and " << b << endl;
    }
};
class B: public A{
public:
    void func(double a){ // 这是一个新的函数，直接覆盖了A中同名函数，而不是对A中的func重写
        cout << a << endl;
    }
    void funv(int a){
        cout << "this is funv in B class" << endl;
        cout << a << endl;
    }
};

class C{ // 默认private
public:
    C()=default;
    void print(string s){
        cout << s << endl;
    }
};

class AbstractClass {
public:
    virtual void abstractFunction()=0;// 纯虚函数
    void normalFunction(){
        cout << "This is a normal function~" << endl;
    }
};
class ConcreteClass:public AbstractClass{
public:
    void abstractFunction() override{
        cout << "Implementation of abstractFunction in ConcreteClass" << endl;
    }
};
int main(){

    // Circle circle(5.0);
    // double area = circle.getArea();
    // // Circle类继承了Shape类的getArea函数，并重写了
    // cout << area << endl;

    // B* t = new B();
    // t->func(1);


    // auto var = new C();
    // var->print("Ss");
    // auto a= new AbstractClass(); // 错误 抽象类不能实例化
    // auto b = new ConcreteClass();
    // b->abstractFunction();
    // b->normalFunction();

    A* a = new B();
    cout << typeid(a).name() << endl;
    a->funv(1,2);
    auto b = new B();
    cout << typeid(b).name() << endl;
    return 0;
}