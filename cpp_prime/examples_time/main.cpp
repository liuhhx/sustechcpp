#include "../time.hpp"
int main(){
    MyTime t1(1,59);
    MyTime t4 = t1++;
    MyTime t5 = ++t1;

    std::cout << "t1 is : " << t1 << std::endl;
    std::cout << "t4 is : "<< t4 << std::endl;
    std::cout << "t5 is : "<< t5 << std::endl;
    return 0;
}