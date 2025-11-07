// House Robber II

// Link: https://leetcode.com/problems/house-robber-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, vector<int>&nums, vector<int>&dp){
        int n = nums.size();
        if(i >= n)
        return 0;

        if(dp[i] != -1)
        return dp[i];

        int not_pick = f(i+1, nums, dp);
        int pick = nums[i] + f(i+2, nums, dp);

        return dp[i] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        if(n == 2)
        return max(nums[0], nums[1]);

        vector<int>first;
        vector<int>second;
        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);

        for(int i=0; i<n-1; i++){
            first.push_back(nums[i]);
        }
        for(int i=1; i<n; i++){
            second.push_back(nums[i]);
        }

        return max(f(0, first, dp1), f(0, second, dp2));
    }
};
