// Assign Cookies

// Link: https://leetcode.com/problems/assign-cookies/description/

#include <bits/stdc++.h>
using namespace std;

// Greedy

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int l=0, r=0;
        while(l<m && r<n){
            if(g[r]<=s[l]){
                r++;
            }
            l++;
        }

        return r;
    }
};

// Recursion + Memoization

class Solution {
public:
    int f(int i, int j, vector<int>& g, vector<int>& s, vector<vector<int>>& dp){
        int n = g.size();
        int m = s.size();

        if(i == n || j == m) 
        return 0;

        if(dp[i][j] != -1) 
        return dp[i][j];

        int can = 0;
        if(s[j] >= g[i]){
            can = 1 + f(i+1, j+1, g, s, dp);
        }

        int cant = f(i, j+1, g, s, dp);

        return dp[i][j] = max(cant, can);
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return f(0, 0, g, s, dp);
    }
};

// Tabulation

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int ans = dp[i][j+1];
                if(s[j] >= g[i]) 
                ans = max(ans, 1 + dp[i+1][j+1]);
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
};
