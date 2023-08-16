#include <stdio.h>
#include <iostream>

/*
字节序：字节在内存中的存储的顺序
小端字节序：高位字节存储在高位地址
大端字节序：低位字节存储在高位地址

*/
void byteorder(){
    union{
        short value;
        char union_bytes[ sizeof(short) ];
    } test;
    test.value = 0x0102;
    if((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1)){
        printf("little endian\n");
    }else{
        printf("big endian\n");
    }
}


int main(){
    byteorder();
    int a = 0;
    std::cout << sizeof(a) << std::endl;
}