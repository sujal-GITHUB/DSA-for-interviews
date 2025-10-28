// Triangle

// Link: https://leetcode.com/problems/triangle/description/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        if(i == n - 1)
            return triangle[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int d = triangle[i][j] + f(i + 1, j, triangle, dp);
        int dd = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(d, dd);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, dp);
    }
};

// Tabulation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>>dp(n, vector<int>(n,-1));

        for(int j=0;j<n;j++)
        dp[n-1][j] = triangle[n-1][j];

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dd = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(d,dd);
            }
        }

        return dp[0][0];
    }
};