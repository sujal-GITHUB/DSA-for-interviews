// Unique Paths II

// Link: https://leetcode.com/problems/unique-paths-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();

        if(grid[i][j] == 1)
        return dp[i][j] = 0;

        if(i == m-1 && j == n-1)
        return 1;

        if(dp[i][j] != -1)
        return dp[i][j];

        int down = 0;
        int right = 0;

        if(j+1 < n && grid[i][j+1] != 1){
            right = f(i, j+1, grid, dp);
        }
        if(i+1 < m && grid[i+1][j] != 1){
            down = f(i+1, j, grid, dp);
        }

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1)); // no. of ways at i, j

        return f(0, 0, grid, dp);
    }
};

// Tabulation

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if(grid[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if(i > 0)
                    dp[i][j] += dp[i - 1][j];
                if(j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
