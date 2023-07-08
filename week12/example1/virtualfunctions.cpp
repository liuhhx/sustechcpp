#include <iostream>
class Person {
public:
    void print() {
        std::cout << "This is Person class" << std::endl;
    }
};

class Student : public Person {
public:
    void print() {
        std::cout<<"This is Student class" << std::endl;
    }
};


int main(){
    Person *p;
    Student *s;
    p->print();
    s->print();
    Person* ptr = new Student();
    ptr->print();
    // Student* st = new Person();
    // st->print();
    return 0;
}