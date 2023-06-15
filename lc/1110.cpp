#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
private:
    vector<TreeNode*> res;
    set<int> delNode;
public:
    int del(TreeNode* root){
        if(root==nullptr)return 0;
        int l = del(root->left);
        int r = del(root->right);
        if(l==1)root->left = nullptr;
        if(r==1)root->right = nullptr;
        if(delNode.count(root->val)>0){
            if(root->left)res.push_back(root->left);
            if(root->right)res.push_back(root->right);
            return 1;
        }
        return 0;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>_delNode(to_delete.begin(), to_delete.end());
        this->delNode = _delNode;
        int t = del(root);
        if(t==0)res.push_back(root);
        return res;
    }
};