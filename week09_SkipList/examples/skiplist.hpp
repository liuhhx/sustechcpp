#include "time.h"
#pragma once
#define MAX_L 16;

template <typename T>
struct SkipNode {
    T key;
    T value;
    struct SkipNode * next[1];
};

typedef struct SkipNode<int> IntSkipNode;

typedef struct SkipList {
    int max_level;
    IntSkipNode* head;
}SkipList;

// 创建节点
IntSkipNode* CreateNode(int level, int key, int value);

// 创建跳表
SkipList* CreateSkipList();

// 随机算法
int randomLevel();

// 插入节点
bool Insert(SkipList* list, int key, int value);

// 删除节点
bool Erase(SkipList* list, int key);

// 查找
int Search(SkipList* list, int key);

// 打印
void Print(SkipList* list);

// 释放
void Free(SkipList* list);