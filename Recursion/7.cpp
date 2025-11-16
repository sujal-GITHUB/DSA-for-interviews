// Permutations

// Link: https://leetcode.com/problems/permutations/description/

// TC = O(n × n!)
// SC = O(n × n!)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, vector<int>&nums, vector<vector<int>>&ans){
        int n = nums.size();
        if(i == n){
            ans.push_back(nums);
            return;
        }

        for(int j=i; j<n; j++){
            swap(nums[i], nums[j]);
            f(i+1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        f(0, nums, ans);
        return ans;
    }
};