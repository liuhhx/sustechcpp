#include <iostream>
using namespace std;
// 当派生类定义了与父类相同名称的函数时，这个过程称为函数隐藏（function hiding）。
// 当派生类重写（override）父类的虚函数时，派生类提供了自己的实现，并且在运行时会根据对象的动态类型选择调用相应的函数。
// 这种多态性的机制允许在运行时选择正确的函数实现，而不是在编译时静态地决定调用哪个函数。

// 多态性：通过虚函数和动态绑定来实现。 区别于覆盖
class Animal {
public:
    virtual void makeSound(){
        cout << "The animal makes a sound." << endl;
    }
};

class Cat:public Animal{
public:
    void makeSound(){
        cout << "The cat makes a sound." << endl;
    }
};

class Dog:public Animal{
public:
    void makeSound(){
        cout << "The dog makes a sound." << endl;
    }
};

int main(){
    auto cat = new Cat();
    auto dog = new Dog();
    cat->makeSound();
    dog->makeSound();
    return 0;
}