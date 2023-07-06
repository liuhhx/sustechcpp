#include "student.hpp"
#include <iostream>

void Student::setGender(bool isMale){
    male = isMale;
}

void Student::printInfo(){
    std::cout << "Name: "<< name <<std::endl;
    std::cout << "Born in: "<< born <<std::endl;
    std::cout << "Gender: "<<  <<std::endl;
}