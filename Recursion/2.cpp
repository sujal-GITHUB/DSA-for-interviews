// Subset Sums - II

// Link: https://leetcode.com/problems/subsets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans){
        int n = nums.size();
        if(i == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        f(i+1, nums, temp, ans);
        temp.pop_back();

        while(i+1<nums.size() && nums[i] == nums[i+1])
        i++;
        f(i+1, nums, temp, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        f(0, nums, temp, ans);
        return ans;
    }
};