// Simple is beautiful!

// 打印会阻塞 最好存在变量里
// 打表法，比如三角函数，但是会损失精度

// 并行化
#include <omp.h>
#include <vector>
#include <iostream>

int main(){
    int n = 100;
    std::vector<int> a(n,1), b(n,2), c(n,0);
    #pragma omp parallel for
    for(size_t i=0;i<n;++i){
        c[i] = a[i]+b[i];
    }
    return 0;
}