// Minimum Falling Path Sum

// Link: https://leetcode.com/problems/minimum-falling-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if(j < 0 || j >= n)
            return 1e9;
        if(i == n - 1)
            return matrix[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];

        int d = matrix[i][j] + f(i + 1, j, matrix, dp);
        int dl = matrix[i][j] + f(i + 1, j - 1, matrix, dp);
        int dr = matrix[i][j] + f(i + 1, j + 1, matrix, dp);

        return dp[i][j] = min({d, dl, dr});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 1e9;
        for(int j = 0; j < n; j++) {
            ans = min(ans, f(0, j, matrix, dp));
        }
        return ans;
    }
};


// Tabulation

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        for(int j=0; j<n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        int ans = 1e9;
        
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int l = 1e9, r = 1e9;

                int c = matrix[i][j] + dp[i+1][j];

                if(j-1 >= 0)
                l = matrix[i][j] + dp[i+1][j-1];

                if(j+1 < n)
                r = matrix[i][j] + dp[i+1][j+1];

                dp[i][j] = min({c, l ,r});
            }
        }

        for(int j=0; j<n; j++){
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};