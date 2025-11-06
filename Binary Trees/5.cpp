// Construct Binary Tree from Preorder and Inorder Traversal

// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode* f(int ps, int pe, vector<int>& preorder, int is, int ie, vector<int>& inorder, unordered_map<int, int>&mpp){
        if(is > ie || ps > pe)
        return nullptr;

        TreeNode* root = new TreeNode(preorder[ps]);

        int mid = mpp[root->val];
        int left = mid - is;

        root->left = f(ps+1, ps+left, preorder, is, mid-1, inorder, mpp);
        root->right = f(ps+left+1, pe, preorder, mid+1, ie, inorder, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        int n = inorder.size();

        return f(0, n-1, preorder, 0, n-1, inorder, mpp);
    }
};