// Unique Paths

// Link: https://leetcode.com/problems/unique-paths/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i == m-1 && j == n-1)
        return 1;

        if(dp[i][j] != -1)
        return dp[i][j];

        int right = 0, down = 0;

        if(j+1 < n)
        right = f(i, j+1, m, n, dp);
        if(i+1 < m)
        down = f(i+1, j, m, n, dp);

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, dp);
    }
};

// Tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: only one way to reach (0,0)
        dp[0][0] = 1;

        // Fill the dp table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue; // already set base case

                int up = 0, left = 0;

                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }

        // Answer is number of paths to bottom-right corner
        return dp[m - 1][n - 1];
    }
};
