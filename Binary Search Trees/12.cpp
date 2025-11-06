// Two Sum IV - Input is a BST

// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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

// Approach 1

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }
private:
    bool dfs(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) 
        return false;

        if (seen.count(k - node->val)) 
        return true;

        seen.insert(node->val);

        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};

// Approach 2

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        inorder(root, a);
        int i = 0, j = (int)a.size() - 1;
        while (i < j) {
            long sum = (long)a[i] + a[j];
            if (sum == k) return true;
            if (sum < k) ++i; else --j;
        }
        return false;
    }
private:
    void inorder(TreeNode* n, vector<int>& a) {
        if (!n) return;
        inorder(n->left, a);
        a.push_back(n->val);
        inorder(n->right, a);
    }
};
