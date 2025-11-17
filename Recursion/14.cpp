// Subsets

// Link: https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        int n = nums.size();
        if(i == n){
            ans.push_back(temp);
            return;
        }

        // Exclude
        f(i+1, nums, ans, temp);

        // Include nums[i]
        temp.push_back(nums[i]);
        f(i+1, nums, ans, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        f(0, nums, ans, temp);
        return ans;
    }
};