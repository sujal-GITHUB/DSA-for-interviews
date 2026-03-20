// Postorder Traversal

// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
private:
    void help(TreeNode* root, vector<int>&ans){
        if(root == nullptr)
        return;

        help(root->left, ans);
        help(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        help(root, ans);
        return ans;
    }
};


// Iterative

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;

        if(!root)
        return ans;

        stack<TreeNode* >st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if(node->left)
            st.push(node->left);

            if(node->right)
            st.push(node->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};