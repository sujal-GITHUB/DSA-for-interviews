// Inorder Traversal

// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    void f(TreeNode* root, vector<int>& ans){
        if(!root)
        return;

        f(root->left, ans);
        ans.push_back(root->val);
        f(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        f(root, ans);
        return ans;
    }
};

// Iterative

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        if(!root)
        return {};

        stack<TreeNode* >st;
        TreeNode* curr = root;

        while(curr || !st.empty()){
            //Go left
            while(curr){
                st.push(curr);
                curr = curr->left;
            }

            //Process node
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            //Go to right subtree
            curr = curr->right;
        }

        return ans;
    }
};