#include "skiplist.hpp"
#include <iostream>

int main(){
    auto sk = new SkipList(10);
    for(int i=0;i<10;++i){
        sk->insert(i);
    }
    sk->printList();

    for(int i=0;i<10;++i){
        if(sk->search(i)){
            std::cout<< "找到了" << std::endl;
        }
    }

    return 0;
}