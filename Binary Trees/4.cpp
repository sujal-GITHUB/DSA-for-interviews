// Postorder Traversal

// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }

private:
    void dfs(TreeNode* node, int depth, vector<vector<int>>& ans) {
        if(!node) 
        return;

        if(depth == ans.size()){
            ans.push_back({});
        }

        ans[depth].push_back(node->val);

        dfs(node->left, depth + 1, ans);
        dfs(node->right, depth + 1, ans);
    }
};


// Iterative

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;

        if(root == nullptr)
        return ans;

        while(!q.empty()){
            int sz = q.size();
            vector<int>level;

            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }

                level.push_back(node->val);
            }

            ans.push_back(level);
        }

        return ans;
    }
};