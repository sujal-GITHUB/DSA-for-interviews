// Rod Cutting

// Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
  public:
    int f(int idx, int rem, vector<int>&price ,vector<vector<int>>& dp){
        if(idx == 0){
            return rem*price[0];
        }
        
        if(dp[idx][rem] != -1)
        return dp[idx][rem];
        
        int not_take = f(idx-1, rem, price, dp);
        int take = -1e8;
        int rodLen = idx+1;
        
        if(rodLen <= rem){
            take = price[idx] + f(idx, rem-rodLen, price, dp);
        }
        
        return dp[idx][rem] = max(take, not_take);
    }
  
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        
        return f(n-1, n, price, dp);
    }
};

// Tabulation

class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 0));

        for(int rem=0; rem<=n; rem++){
            dp[0][rem] = rem * price[0];
        }

        for(int idx=1; idx<n; idx++){
            int rodLen = idx + 1;
            for(int rem=0; rem<=n; rem++){
                int not_take = dp[idx-1][rem];
                int take = -1e8;
                if(rodLen <= rem)
                    take = price[idx] + dp[idx][rem - rodLen];
                dp[idx][rem] = max(take, not_take);
            }
        }

        return dp[n-1][n];
    }
};
