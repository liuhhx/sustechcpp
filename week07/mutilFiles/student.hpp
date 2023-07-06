#pragma once
// 只被include一次
#include <cstring>
class Student {
private:
    char name[4];
    int born;
    bool male;
public:
    void setName(const char* s){
        strncpy(name, s, sizeof(name));
    }
    void setBorn(int b){
        born = b;
    }
    // 内部定义
    void setGender(bool isMale);
    void printInfo();
}