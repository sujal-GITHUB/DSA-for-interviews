// Partition Equal Subset Sum

// Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    bool f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(sum == 0)
            return true;
        if(i == n)
            return false;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        bool not_take = f(i + 1, sum, nums, dp);
        bool take = false;
        if(nums[i] <= sum)
            take = f(i + 1, sum - nums[i], nums, dp);
        return dp[i][sum] = (take || not_take);
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1)
            return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(0, target, nums, dp);
    }
};

// Tabulation

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)
        return false;
        sum /= 2;

        vector<bool> dp(sum+1, false);
        dp[0] = true;

        for(int num: nums){
            for(int j=sum; j>=num; j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[sum];
    }
};
