// Validate Binary Search Tree

// Link: https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        return f(root, LLONG_MIN, LLONG_MAX);
    }

    bool f(TreeNode* root, long long l, long long r){
        if(!root)
        return true;

        if(root->val <= l || root->val >= r)
        return false;

        return f(root->left, l, root->val) && f(root->right, root->val, r);
    }
};