// Binary Tree Maximum Path Sum

// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int maxPathSum(TreeNode* root) {
        int maxSum = -1e8;
        helper(root, maxSum);
        return maxSum;
    }

    int helper(TreeNode* root, int &maxSum){
        if(!root)
        return 0;

        int left = max(0, helper(root->left, maxSum));
        int right = max(0, helper(root->right, maxSum));

        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left, right);
    }
};