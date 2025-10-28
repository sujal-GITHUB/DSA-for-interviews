// Minimum Path Sum

// Link: https://leetcode.com/problems/minimum-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();

        if(i == m-1 && j == n-1)
        return grid[i][j];

        if(dp[i][j] != -1)
        return dp[i][j];

        int down = 1e9, right = 1e9;

        if(i+1 < m)
        down = grid[i][j] + f(i+1, j, grid, dp);
        if(j+1 < n)
        right = grid[i][j] + f(i, j+1, grid, dp);

        return dp[i][j] = min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return f(0, 0, grid, dp);
    }
};

// Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;

                int up = 1e9, left = 1e9;
                if(i > 0) up = grid[i][j] + dp[i - 1][j];
                if(j > 0) left = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }

        return dp[m - 1][n - 1];
    }
};
