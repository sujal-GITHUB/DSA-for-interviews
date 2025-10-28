// Partition Array Into Two Arrays to Minimize Sum Difference

// Link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

#include <bits/stdc++.h>
using namespace std;

// Iterative

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        long long tsum = accumulate(nums.begin(), nums.end(), 0);
        long long minDiff = LLONG_MAX;

        set<long long> prev;
        prev.insert(0);

        for (int i = 0; i < n; i++) {
            set<long long> curr;
            for (auto s : prev) {
                curr.insert(s + nums[i]);
                curr.insert(s);
            }
            prev = curr;
        }

        for (auto s : prev) {
            minDiff = min(minDiff, abs(tsum - 2 * s));
        }
        return minDiff;
    }
};

// Recursion + Memoization

class Solution {
public:
    bool f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(sum == 0)
            return true;
        if(i == 0)
            return nums[0] == sum;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        bool not_take = f(i - 1, sum, nums, dp);
        bool take = false;
        if(nums[i] <= sum)
            take = f(i - 1, sum - nums[i], nums, dp);
        return dp[i][sum] = (take || not_take);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        int k = tsum;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        for(int i = 0; i <= tsum / 2; i++)
            f(n - 1, i, nums, dp);
        int ans = 1e9;
        for(int s = 0; s <= tsum / 2; s++) {
            if(dp[n - 1][s])
                ans = min(ans, abs(tsum - 2 * s));
        }
        return ans;
    }
};

// Tabulation

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(tsum + 1, false));

        for(int i = 0; i < n; i++)
            dp[i][0] = true;
        if(nums[0] <= tsum)
            dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++) {
            for(int s = 1; s <= tsum; s++) {
                bool not_take = dp[i - 1][s];
                bool take = false;
                if(nums[i] <= s)
                    take = dp[i - 1][s - nums[i]];
                dp[i][s] = (take || not_take);
            }
        }

        int ans = 1e9;
        for(int s = 0; s <= tsum / 2; s++) {
            if(dp[n - 1][s])
                ans = min(ans, abs(tsum - 2 * s));
        }
        return ans;
    }
};