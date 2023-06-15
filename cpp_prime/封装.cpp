#include <iostream>
using namespace std;
// 封装：将数据和操作数据的函数封装在一个单元中，即类。封装可以隐藏类的内部实现细节，使得类的用户只能通过公共接口来访问和操作类的数据。封装提供了数据的安全性和可维护性，同时也支持代码的重用和模块化。
class Rectangle {
private:
    double length;
    double width;
public:
    Rectangle() = default; // 默认构造函数
    void setDimensions(double len, double wid){
        length = len;
        width = wid;
    }
    double getArea(){
        return length*width;
    }
};
int main(){
    Rectangle* rc = new Rectangle();
    rc->setDimensions(2,3);
    double res = rc->getArea();
    cout << res << endl;
    delete rc;
    rc = nullptr; // 如果不把rc指向nullptr，那么rc就成了野指针。
    // delete操作只会释放rc指向的那块内存，而不会销毁rc变量
    if(rc==nullptr)cout << "已销毁" <<endl;
    else cout << rc->getArea()<<endl;;
    return 0;
}