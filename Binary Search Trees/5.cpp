// Predecessor and Successor

// Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

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
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(!root)
        return {nullptr, nullptr};
        
        Node* pre = nullptr;
        Node* suc = nullptr;
        
        Node* node = root;
        while(node){
            if(node->data == key){
                if(node->left) {
                    Node* tmp = node->left;
                    while(tmp->right)
                    tmp = tmp->right;
                    pre = tmp;
                }
                
                if(node->right){
                    Node* tmp = node->right;
                    while(tmp->left)
                    tmp = tmp->left;
                    suc = tmp;
                }
                break;
            }
            
            else if(key < node->data){
                suc = node;        
                node = node->left;
            } 
            else{
                pre = node;        
                node = node->right;
            }
        }
        
        return {pre, suc};
    }
};