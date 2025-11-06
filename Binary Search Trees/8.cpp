// Construct Binary Search Tree from Preorder Traversal

// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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

// Brute Force

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = nullptr;
        for(int x: pre) 
        root = ins(root, x);

        return root;
    }

    TreeNode* ins(TreeNode* root, int x){
        if(!root) 
        return new TreeNode(x);

        if(x < root->val) 
        root->left = ins(root->left, x);

        else 
        root->right = ins(root->right, x);
        
        return root;
    }
};


// Iterative

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if(pre.empty()) return nullptr;

        TreeNode* root = new TreeNode(pre[0]);
        stack<TreeNode*> st;
        st.push(root);

        for(int i=1;i<pre.size();i++){
            TreeNode* cur = new TreeNode(pre[i]);
            TreeNode* temp = nullptr;

            while(!st.empty() && pre[i] > st.top()->val){
                temp = st.top();
                st.pop();
            }

            if(temp) temp->right = cur;
            else st.top()->left = cur;

            st.push(cur);
        }
        return root;
    }
};

// Recursive

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder, i, INT_MAX);
    }

    TreeNode* helper(vector<int>& arr, int &i,int bound) {
        if(i == arr.size() || arr[i] > bound)
        return nullptr;

        TreeNode* root = new TreeNode(arr[i++]);
        root->left = helper(arr,i,root->val);
        root->right = helper(arr,i,bound);
        return root;
    }
};