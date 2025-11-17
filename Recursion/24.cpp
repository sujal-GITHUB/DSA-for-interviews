// Expression Add Operators

// Link: http://leetcode.com/problems/expression-add-operators/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int pos, const string &num, int target, long long cur, long long last, string &expr, vector<string>& ans){
        int n = num.size();
        if(pos == n){
            if(cur == target) ans.push_back(expr);
            return;
        }

        for(int len = 1; pos + len <= n; ++len){
            if(len > 1 && num[pos] == '0') break;
            string part = num.substr(pos, len);
            long long val = stoll(part);
            int old = expr.size();

            if(pos == 0){
                expr += part;
                dfs(pos + len, num, target, val, val, expr, ans);
                expr.resize(old);
            } else {
                expr += '+';
                expr += part;
                dfs(pos + len, num, target, cur + val, val, expr, ans);
                expr.resize(old);

                expr += '-';
                expr += part;
                dfs(pos + len, num, target, cur - val, -val, expr, ans);
                expr.resize(old);

                expr += '*';
                expr += part;
                dfs(pos + len, num, target, cur - last + last * val, last * val, expr, ans);
                expr.resize(old);
            }
        }
    }

    void f(int i, string num, int target, vector<string>& ans){
        string expr = "";
        if(!num.empty()) 
        dfs(0, num, target, 0LL, 0LL, expr, ans);
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        f(0, num, target, ans);
        return ans;
    }
};
