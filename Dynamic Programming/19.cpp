// Coin Change

// Link: https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, vector<int>& coins, int n, int amount, vector<vector<int>>&dp){
        if(i == n-1){
            if(amount%coins[i] == 0)
            return amount/coins[i];

            return 1e9;
        }

        if(dp[i][amount] != -1)
        return dp[i][amount];

        int not_pick = f(i+1, coins, n, amount, dp);
        int pick = 1e9;
        if(coins[i] <= amount){
            pick = 1 + f(i, coins, n, amount-coins[i], dp);
        }

        return dp[i][amount] = min(pick, not_pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.rbegin(), coins.rend());

        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));

        int ans = f(0, coins, n, amount, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};

// Tabulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.rbegin(), coins.rend());
        
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        for(int t=0; t<=amount; t++){
            if(t % coins[n-1] == 0)
                dp[n-1][t] = t / coins[n-1];
        }

        for(int i=n-2; i>=0; i--){
            for(int t=0; t<=amount; t++){
                int not_pick = dp[i+1][t];
                int pick = 1e9;
                if(coins[i] <= t) pick = 1 + dp[i][t-coins[i]];
                dp[i][t] = min(pick, not_pick);
            }
        }

        int ans = dp[0][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};
