// Target Sum

// Link: https://leetcode.com/problems/target-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == 0) {
            if(target == 0 && nums[0] == 0)
                return 2;
            if(target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if(dp[i][target] != -1)
            return dp[i][target];

        int nottake = f(i - 1, target, nums, dp);
        int take = 0;
        if(nums[i] <= target)
            take = f(i - 1, target - nums[i], nums, dp);

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
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return help(nums, target);
    }
};


// Tabulation

class Solution {
public:
    int f(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2; // Two ways: +0 or -0
        else
            dp[0][0] = 1; // One way: just not picking nums[0]

        if (nums[0] != 0 && nums[0] <= target)
            dp[0][nums[0]] = 1; // One way: pick nums[0]

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                int nottake = dp[i - 1][t];
                int take = 0;
                if (t - nums[i] >= 0)
                    take = dp[i - 1][t - nums[i]];

                dp[i][t] = nottake + take;
            }
        }

        return dp[n - 1][target];
    }

    int help(vector<int>& nums, int d) {
        int tsum = 0;
        int n = nums.size();

        for (auto& it : nums)
            tsum += it;

        if (tsum - d < 0 || (tsum - d) % 2 != 0)
            return 0;

        return f(nums, (tsum - d) / 2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return help(nums, target);
    }
};