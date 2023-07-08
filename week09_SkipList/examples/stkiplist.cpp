#include "skiplist.hpp"

// 创建节点
IntSkipNode* CreateNode(int level, int key, int value){
    IntSkipNode* p = new IntSkipNode();
    if(!p)return nullptr;
    p->key = key;
    p->value = value;
    return p;
}

// 创建跳表
SkipList* CreateSkipList(){
    SkipList* list = new SkipList();
    if(!list)return nullptr;
    list->max_level = 0;
    auto node = CreateNode(15, 0, 0);
    
    if(!node){
        delete list;
        return nullptr;
    }

    list->head = node;
    int i = 0;
    for(i;i<16;++i){
        node->next[i] = nullptr;
    }
    srand(time(0));
    return list;
}