// Generate Parentheses

// Link: https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int o, int c, string temp, vector<string>&ans, int n){
        if(temp.length() == n*2){
            ans.push_back(temp);
            return;
        }

        if(o < n){
            f(o+1, c, temp+'(', ans, n);
        }

        if(c < o){
            f(o, c+1, temp+')', ans, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        int i = 0;
        vector<string>ans;

        if(n == 1)
        return {"()"};

        f(0, 0, "", ans, n);
        return ans;
    }
};