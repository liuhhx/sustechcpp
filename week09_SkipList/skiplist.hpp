#pragma once
#include <vector>
#include <bits/stdc++.h>

// 定义节点
// 跳表中的节点：每个节点包含一个值 和 一个指向下一个节点的指针数组
struct SkipNode {
    int value;
    std::vector<SkipNode*> next;
};

// 初始化跳表
// 在跳表中，需要初始化一个头结点和尾节点
class SkipList {
private:
    SkipNode* head;
    SkipNode* tail;
    int maxLevel; // 最大层数
public:
    SkipList(int maxLevel):maxLevel(maxLevel) {
        head = new SkipNode();
        tail = new SkipNode();
        head->value = INT_MIN;
        tail->value = INT_MAX;
        head->next.resize(maxLevel+1, tail);
    }

    // 创建新节点
    void insert(int value) {
        // 创建新节点
        SkipNode* newNode = new SkipNode();
        newNode->value = value;
        newNode->next.resize(randomLevel());

        // 从头结点开始查找插入位置
        SkipNode* curr = head;
        for (int i = maxLevel; i>= 0;--i){
            while(curr->next[i]->value < value) {
                curr = curr->next[i];
            }
            if(i < newNode->next.size()) {
                newNode->next[i] = curr->next[i];
                curr->next[i] = newNode;
            }
        }
    }

private:
    int randomLevel() {
        int level = 0;
        // 根据一定概率确定节点的层数
        while (level < maxLevel && rand()%2 ==0) {
            ++level;
        }
        return level;
    }

public:
    SkipNode* search(int value) {
        SkipNode* curr = head;
        for(int i=maxLevel;i>=0;--i){
            while(curr->next[i]->value < value){
                curr = curr->next[i];
            }
        }
        if(curr->next[0]->value == value){
            return curr->next[0];
        }
        return nullptr;
    }

    void printInfo(){
        auto curr = head;
        while(curr!=nullptr && curr->next[0]!=nullptr){
            std::cout << curr->value << std::endl;
            curr = curr->next[0];
        }
    }

    void printList() {
        for (int level = maxLevel; level >= 0; --level) {
            std::cout << "Level " << level << ": ";
            SkipNode* current = head->next[level];
            while (current != tail) {
                std::cout << current->value << " ";
                current = current->next[level];
            }
            std::cout << std::endl;
        }
    }
};

