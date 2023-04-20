// c++ 11 
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    vector<string> msg{"Hello", "C++", "World", "!"};
    for(const string& word: msg){
        cout << word << " ";
    }
    cout << endl;
    return 0;
}

// 编译过程
// g++ hello.cpp
// g++ hello.cpp --std==c++11 // g++默认标准比11低， 默认生成a.out
// g++ hello.cpp --std==c++11 -o hello // 指定生成可执行文件名
// ./hello  // execute