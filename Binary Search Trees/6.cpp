// Lowest Common Ancestor of a Binary Search Tree

// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

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
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
        return nullptr;

        if(root->val > p->val && root->val > q->val)
        return f(root->left, p, q);

        else if(root->val < p->val && root->val < q->val)
        return f(root->right, p, q);
        
        else
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root, p , q);
    }
};