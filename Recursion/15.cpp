// Check if there exists a subsequence with sum K

// Link: https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
  public:
    bool f(int i, int n, vector<int>& arr, int k){
        if(k == 0){
            return true;
        }
        
        if(i == n)
        return false;
        
        // pick
        if(f(i+1, n, arr, k-arr[i]))
        return true;
        
        // not_pick
        if(f(i+1, n, arr, k))
        return true;
    }
  
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return f(0, n, arr, k);
    }
};

// Approach 2

class Solution {
  public:
    bool f(int i, int n, vector<int>& arr, int k, vector<vector<int>>&dp){
        if(k == 0){
            return true;
        }
        
        if(k < 0)
        return false;
        
        if(i == n)
        return false;
        
        if(dp[i][k] != -1)
        return dp[i][k];
        
        bool pick = false;
        bool not_pick = false;
        
        // pick
        if(arr[i] <= k)
        pick = f(i+1, n, arr, k-arr[i], dp);
        
        // not_pick
        not_pick = f(i+1, n, arr, k, dp);
        
        return dp[i][k] = pick || not_pick;
    }
  
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return f(0, n, arr, k, dp);
    }
};