// Search in a Binary Search Tree

// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
        return nullptr;

        if(root->val == val)
        return root;

        if(val < root->val)
        return searchBST(root->left, val);
        
        return searchBST(root->right, val);
    }
};