// Valid Parenthesis String

// Link: https://leetcode.com/problems/valid-parenthesis-string/description/

#include <bits/stdc++.h>
using namespace std;

// Recusrsion + Memoization
// TC : O(3^n) -> Without memoization
// TC : O(n*n) -> With memoization
// SC : O(n*n)

class Solution {
public:
    bool f(int i, int o, string &s, vector<vector<int>>&dp){
        int n = s.size();

        if(o < 0) 
        return false;

        if(i == n){
            return o==0;
        }

        if(dp[i][o] != -1)
        return dp[i][o];

        bool open = false;
        bool close = false;
        bool ast = false;

        if(s[i] == '('){
            open = f(i+1, o+1, s, dp);
        }
        else if(s[i] == ')' && o>0){
            close = f(i+1, o-1, s, dp);
        }
        else if(s[i] == '*'){
            ast = f(i+1, o+1, s, dp) || f(i+1, o, s, dp) || (o>0 && f(i+1, o-1, s, dp));
        }

        return dp[i][o] = (open || close || ast);
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return f(0, 0, s, dp);
    }
};

// Tabulation

class Solution {
public:
	bool checkValidString(string s){
		int n = s.size();
		vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

		dp[n][0] = 1;

		for(int i = n-1; i >= 0; i--){
			for(int o = 0; o <= n; o++){

				bool open = false;
				bool close = false;
				bool ast = false;

				if(s[i] == '('){
					if(o+1 <= n)
						open = dp[i+1][o+1];
				}
				else if(s[i] == ')'){
					if(o > 0)
						close = dp[i+1][o-1];
				}
				else{
					if(o+1 <= n)
						ast = ast || dp[i+1][o+1];
					ast = ast || dp[i+1][o];
					if(o > 0)
						ast = ast || dp[i+1][o-1];
				}

				dp[i][o] = (open || close || ast);
			}
		}

		return dp[0][0];
	}
};


// Greedy 
// TC : O(n)
// SC : O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int o = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '*')
            o++;
            else
            o--;

            if(o < 0)
            return false;
        }

        o = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == ')' || s[i] == '*')
            o++;
            else
            o--;

            if(o < 0)
            return false;
        }

        return true;
    }
};