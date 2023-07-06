// 函数模板
// 当函数实现逻辑相同的情况，用函数模板
// 模板是一个虚拟的概念
// 编译器一定会生成一个实例 隐式实例化
// 可以手动去写实例
#include<bits/stdc++.h>
using namespace std;
template<typename T>
T sum(T x, T y){
    cout <<"The input type is " << typeid(T).name() << endl;
    return x+y;
};
// template double sum<double>(doul)




template<typename T>
T add(T x, T y){
    return x+y;
}
class Point{
public:
    int x;
    int y;
    Point(int _x, int _y):x(_x),y(_y){}
    Point():x(0),y(0){}
    Point operator+(Point& other){
        other.x+=x;
        other.y+=y;
        return other;
    }
};
// 自定义的类型如果要用上面的模板 需要特例化，区别就是在template后面加<>
template<>
Point sum<Point>(Point pt1, Point pt2){
    cout <<"The input type is " << typeid(pt1).name() << endl;
    // The input type is 5Point 这个 5 是Point的长度 也就是是由类型名称的长度。
    Point pt3 = Point();
    pt3.x = pt1.x+pt2.x;
    pt3.y = pt1.y+pt2.y;
    return pt3;
}

int main(){
    // int num1 = 23;
    // int num2 = 24;
    // cout << sum(num1, num2) << endl;
    Point num1 = Point(2,3);
    Point num2 = Point(3,2);
    Point num3 = num1+num2;
    Point num4 = add(num1, num2);
    
    cout << num3.x <<" " << num3.y << endl;
    cout << num4.x << " " << num4.y << endl;

    Point num5 = sum(num3, num4);
    cout << num5.x <<" " << num5.y << endl;
    return 0;
} 