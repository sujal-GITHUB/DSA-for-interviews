// Unbounded Knapsack (Repetition of items allowed)

// Link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
  public:
    int f(int i, vector<pair<int, int>>&vals, int c, vector<vector<int>>&dp){
        int n = vals.size();
        
        if(i == n){
            return 0;
        }
        
        if(dp[i][c] != -1)
        return dp[i][c];
        
        int not_pick = f(i+1, vals, c, dp);
        int pick = 0;
        if(vals[i].first <= c){
            pick = vals[i].second + f(i, vals, c-vals[i].first, dp);
        }
        
        return dp[i][c] = max(pick , not_pick);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        if(n == 0) 
        return 0;
        
        vector<pair<int, int>>vals;
        for(int i=0; i<n; i++){
            vals.push_back({wt[i], val[i]});
        }
        
        vector<vector<int>>dp(n+1, vector<int>(capacity+1, -1));
        return f(0, vals, capacity, dp);
    }
};

// Tabulation

class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        if(n == 0) return 0;

        vector<pair<int,int>> vals;
        for(int i=0; i<n; i++){
            vals.push_back({wt[i], val[i]});
        }

        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

        for(int c=0; c<=capacity; c++){
            if(vals[n-1].first <= c)
                dp[n-1][c] = (c / vals[n-1].first) * vals[n-1].second;
        }

        for(int i=n-2; i>=0; i--){
            for(int c=0; c<=capacity; c++){
                int not_pick = dp[i+1][c];
                int pick = 0;
                if(vals[i].first <= c)
                    pick = vals[i].second + dp[i][c - vals[i].first];
                dp[i][c] = max(pick, not_pick);
            }
        }

        return dp[0][capacity];
    }
};
