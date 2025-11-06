// Recover Binary Search Tree

// Link: https://leetcode.com/problems/recover-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach 1

class Solution {
public:
    vector<int> arr;
    int idx = 0;

    void inorder(TreeNode* root) {
        if(!root) 
        return;

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    void rewrite(TreeNode* root) {
        if(!root) 
        return;

        rewrite(root->left);
        root->val = arr[idx++];
        rewrite(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        sort(arr.begin(), arr.end());

        rewrite(root);
    }
};

// Approach 2

class Solution {
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if(root == nullptr)
        return;

        inorder(root->left);
        if(prev!=nullptr && root->val<prev->val){
            if(first == nullptr){
                first = prev;
                middle = root;
            }

            else
            last = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(root == nullptr)
        return;

        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
        swap(first->val,last->val);
        else
        swap(first->val,middle->val);
    }
};