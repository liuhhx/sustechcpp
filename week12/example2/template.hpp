#include <iostream>

// 函数模板
template<typename T>
T sum(T x, T y){
    std::cout << "The input type is : " << typeid(T).name() << std::endl; 
    return x + y;
}

// 这里有两个概念 function templates 和 template functions
// 前者是上面的壳子，后者是实际生成的函数

// 显式实例化
template double sum<double> (double, double); // 模板的实例化

// 隐式实例化
{
    std::cout << sum<int>(1,2) << std::endl;
}


// 模板类 和 类模板

class IntMat {
    size_t rows;
    size_t cols;
    int* data;
public:
    IntMat(size_t rows, size_t cols): rows(rows), cols(cols){
        data = new int[rows * cols * sizeof(int)]{};
    }
    ~IntMat(){
        delete[] data;
    }
    // = delete 是不要编译器给的默认  
    IntMat(const IntMat&) = delete;
    IntMat& operator=(const IntMat&) = delete;
    int getElement(size_t r, size_t c);
    bool setElement(size_t r, size_t c, int value);
};

class FloatMat {
    size_t rows;
    size_t cols;
    float* data;
public:
    FloatMat(size_t rows, size_t cols): rows(rows), cols(cols){
        data = new float[rows * cols * sizeof(float)]{};
    }
    ~FloatMat(){
        delete[] data;
    }
    FloatMat(const FloatMat&) = delete;
    FloatMat& operator=(const FloatMat&) = delete;
    float getElement(size_t r, size_t c);
    bool setElement(size_t r, size_t c, float value);
};

// 模板类
template<typename T>
class Mat {
    size_t rows;
    size_t cols;
    T* data;
public:
    Mat(size_t rows, size_t cols):rows(rows), cols(cols){
        data = new T[rows*cols*sizeof(T)]{};
    }
    ~Mat(){
        delete[] data;
    }
    Mat(const Mat&) = delete;
    Mat& operator=(const Mat&) = delete;
    T getElement(size_t r, size_t c);
    bool setElement(size_t r, size_t c, T value);
};

// 实例化
template class Mat<int>; // Mat<int> 这是类名