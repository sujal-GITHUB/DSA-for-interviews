// Floor in BST

// Link: https://www.geeksforgeeks.org/problems/floor-in-bst/1

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
    int floor(Node* root, int x) {
        if(!root)
        return -1;
        
        int ans = -1;
        
        while(root){
            if(root->data == x) {
                return x;
            }
            else if(root->data < x){
                ans = root->data;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        
        return ans;
    }
};