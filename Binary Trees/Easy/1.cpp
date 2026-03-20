// Preorder Traversal

// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

// Recursive

class Solution {
public:
    void f(TreeNode* root, vector<int>&ans){
        if(root == nullptr)
        return;

        ans.push_back(root->val);
        f(root->left, ans);
        f(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        f(root, ans);
        return ans;
    }
};

// Iterative

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
        return {};

        vector<int>ans;

        stack<TreeNode* >st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if(node->right)
            st.push(node->right);

            if(node->left)
            st.push(node->left);
        }

        return ans;
    }
};