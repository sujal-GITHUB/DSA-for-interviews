// Perfect Sum Problem

// Link: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
  public:
    int f(int i, vector<int>& arr, int t, vector<vector<int>>&dp){
        int n = arr.size();
        
        if(i == n){
            if(t == 0) 
            return 1;
            
            else 
            return 0;
        }
        
        if(dp[i][t] != -1)
        return dp[i][t];
            
        // leave
        int not_pick = f(i+1, arr, t, dp);
        
        // Pick
        int pick = 0;
        if(arr[i] <= t){
            pick = f(i+1, arr, t-arr[i], dp);
        }
        
        return dp[i][t] = pick + not_pick;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return f(0, arr, target, dp);
    }
};

// Tabulation

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        dp[n][0] = 1;
        
        for(int i=n-1; i>=0; i--){
            for(int t=0; t<=target; t++){
                int not_pick = dp[i+1][t];
                int pick = 0;

                if(arr[i] <= t) 
                pick = dp[i+1][t-arr[i]];
                
                dp[i][t] = pick + not_pick;
            }
        }
        
        return dp[0][target];
    }
};
