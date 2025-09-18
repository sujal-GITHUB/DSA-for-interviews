// Frog Jump

// Link: https://www.geeksforgeeks.org/problems/geek-jump/1

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, vector<int>& height, vector<int>& dp, int n) {
        if (i == n-1) 
        return 0;
        
        if(dp[i] != -1) 
        return dp[i];

        int cost1 = abs(height[i] - height[i+1]) + f(i+1, height, dp, n);
        int cost2 = INT_MAX;
        if(i+2 < n)
            cost2 = abs(height[i] - height[i+2]) + f(i+2, height, dp, n);

        return dp[i] = min(cost1, cost2);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return f(0, height, dp, n);
    }
};


// Tabulation

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n, 0);
        
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
            int one = dp[i-1] + abs(height[i]-height[i-1]);
            
            int two = 1e9;
            if(i-2 >= 0)
            two = dp[i-2] + abs(height[i]-height[i-2]);
            
            dp[i] = min(one, two);
        }
        
        return dp[n-1];
    }
};
