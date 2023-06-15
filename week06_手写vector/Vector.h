#pragma once
#include <iostream>

template<typename T>
class Vector{
    T*      m_data;     // 元素
    size_t  m_size;     // 元素个数
    size_t  m_memSize;  // 内存大小
public:
    Vector():m_data(new T[10]{}), m_size(10), m_memSize(sizeof(T)*10) {}
    Vector(size_t size):m_data(new T[size]{}), m_size(10), m_memSize(sizeof(T)*10) {}

};