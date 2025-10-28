// Subset Sum Problem

// Link: http://geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(i == n) {
            if(target == 0)
                return 1;
            return 0;
        }

        if(dp[i][target] != -1)
            return dp[i][target];

        int nottake = f(i + 1, target, nums, dp);
        int take = 0;
        if(nums[i] <= target)
            take = f(i + 1, target - nums[i], nums, dp);

        return dp[i][target] = nottake + take;
    }

    int help(vector<int>& nums, int d) {
        int tsum = 0;
        for(auto& it : nums)
            tsum += it;
        if(tsum - d < 0 || (tsum - d) % 2 != 0)
            return 0;
        int target = (tsum - d) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return f(0, target, nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return help(nums, target);
    }
};

// Tabulation

class Solution {
    public:

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;
        
        for(int i=1; i<n; i++){
            for(int t=1; t<=sum; t++){
                bool not_pick = dp[i-1][t];

                bool pick = false;
                if(t >= arr[i]){
                    pick = dp[i-1][t-arr[i]];
                }
        
                dp[i][t] = (pick || not_pick);
            }
        }
        return dp[n-1][sum];
    }
};