// Climbing Stairs

// Link: https://leetcode.com/problems/climbing-stairs/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, vector<int>&dp){
        if(i == 0 || i == 1)
        return 1;

        if(dp[i] != -1)
        return dp[i];

        int one = f(i-1, dp);
        int two = f(i-2, dp);

        return dp[i] = one + two;
    }

    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return f(n, dp);
    }
};

// Tabulation

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
        return 1;

        vector<int>dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
