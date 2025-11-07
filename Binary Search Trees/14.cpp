// Largest BST

// Link: https://www.geeksforgeeks.org/problems/largest-bst/1

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
    bool isBST(Node* root, long long low, long long high) {
        if (!root) 
        return true;

        if (root->data <= low || root->data >= high) 
        return false;

        return isBST(root->left, low, root->data) && isBST(root->right, root->data, high);
    }

    int size(Node* root) {
        if (!root) 
        return 0;

        return 1 + size(root->left) + size(root->right);
    }

public:
    int largestBst(Node* root) {
        if (!root) 
        return 0;

        if (isBST(root, LLONG_MIN, LLONG_MAX)) {
            return size(root);
        }
        
        return max(largestBst(root->left), largestBst(root->right));
    }
};

// Approach 2

class Solution {
    struct Info {
        int size;     // size of largest BST in this subtree
        int minv;     // min in this subtree
        int maxv;     // max in this subtree
        bool isBST;   // whether this subtree itself is BST
    };

    Info dfs(Node* root) {
        if (!root) 
        return {0, INT_MAX, INT_MIN, true};

        Info L = dfs(root->left);
        Info R = dfs(root->right);

        if (L.isBST && R.isBST && root->data > L.maxv && root->data < R.minv) {
            int sz = L.size + R.size + 1;
            int mn = min(L.minv, root->data);
            int mx = max(R.maxv, root->data);
            return {sz, mn, mx, true};
        }

        return {max(L.size, R.size), INT_MIN, INT_MAX, false};
    }

<<<<<<< HEAD
    
=======
>>>>>>> 13513edbc235777a33351a06294eb34164081f55
public:
    int largestBst(Node* root) {
        return dfs(root).size;
    }
};