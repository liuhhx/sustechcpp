#include <iostream>
#include <unordered_map>
#include <vector>

// // 实现一
// class UnionFind {
// private:
//     std::unordered_map<int, int> parents;
// public:
//     int find(int x) {
//         int root = x;
//         while(parents[root]!=-1){
//             root = parents[root];
//         }
//         // 这个循环会一直找到x的祖先

//         while(x!=root){
//             int raw_parent = parents[x];
//             parents[x] = root;
//             x = raw_parent;
//         }
//         // 路径压缩

//         return root;
//     }
//     // 判断节点x和节点y是否连通
//     bool isConnected(int x, int y){
//         return find(x) == find(y);
//     }

//     // 合并
//     void merge(int x,int y) {
//         int root_x = find(x);
//         int root_y = find(y);
//         if(root_x!=root_y){
//             parents[root_x] = root_y;
//         }
//     }

//     void add(int x){
//         if(!parents.count(x)){
//             parents[x] = -1;
//         }
//     }
// };



// 实现二 用数组，没有进行路径压缩

class UnionFind {
private:
    std::vector<int> pa;
public:
    UnionFind(int size):pa(std::vector<int>(size)){
        for(int i=0;i<size;++i){
            pa[i] = i;
        }
    }

    int find(int x){
        return pa[x] == x? x: find(pa[x]);
    }

    void merge(int x, int y){
        // 合并条件
        // 比如按字典序
        int root_x = find(x);
        int root_y = find(y);
        if(root_x <= root_y){
            pa[y] = root_x;
        }else{
            pa[x] = root_y;
        }
    }
    bool isConnected(int x,int y){
        return find(x)==find(y);
    }
}