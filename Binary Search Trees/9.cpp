// Insert into a Binary Search Tree

// Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
    TreeNode* insertIntoBST(TreeNode* a, int x) { 
        if(!a) 
        return new TreeNode(x);

        if(x<a->val)
            a->left=insertIntoBST(a->left,x);
        else 
            a->right=insertIntoBST(a->right,x);

        return a;
    }
};