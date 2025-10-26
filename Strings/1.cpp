// Remove Outermost Parentheses

// Link: https://leetcode.com/problems/remove-outermost-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                cnt++;
                if(cnt-1 != 0){
                    ans += s[i];
                }
            }
            else if(s[i] == ')'){
                cnt--;
                if(cnt != 0){
                    ans+= s[i];
                }
            }
        }
        return ans;
    }
};