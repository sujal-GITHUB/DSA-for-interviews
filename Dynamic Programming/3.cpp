// House Robber

// Link: https://leetcode.com/problems/house-robber/description/

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
        vector<int>dp(n+1, -1);
        return f(0, nums, dp);
    }
};


// Tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
    
        if(n == 0)
        return 0;

        if(n == 1) 
        return nums[0];

        vector<int>dp(n, -1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            int not_pick = dp[i-1];
            int pick = nums[i] + dp[i-2];

            dp[i] = max(pick, not_pick);
        }

        return dp[n-1];
    }
};