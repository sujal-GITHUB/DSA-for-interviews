// Coin Change II

// Link: https://leetcode.com/problems/coin-change-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, int t, vector<int>& coins, vector<vector<int>>& dp){
        int n = coins.size();

        if(i == n-1){
            if(t % coins[n-1] == 0) 
            return 1;

            return 0;
        }

        if(dp[i][t] != -1) 
        return dp[i][t];

        int nottake = f(i+1, t, coins, dp);
        int take = 0;
        if(coins[i] <= t)
            take = f(i, t - coins[i], coins, dp);

        return dp[i][t] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(0, amount, coins, dp);
    }
};

// Tabulation

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int i=0;i<=amount;i++){
            if(i%coins[0] == 0)
            dp[0][i] = 1;
        }

        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int nottake = dp[i-1][t];
                int take = 0;
                if(coins[i]<=t)
                take = dp[i][t-coins[i]];

                dp[i][t] = take + nottake;
            }
        }

        return dp[n-1][amount];
    }
};