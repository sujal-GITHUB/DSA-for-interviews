// Convert Sorted Array to Binary Search Tree

// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
    TreeNode* f(int l, int r, vector<int>& nums){
        if(l>r)
        return nullptr;

        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root ->left = f(l, mid-1, nums);
        root->right = f(mid+1, r, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        return f(l, r, nums);
    }
};