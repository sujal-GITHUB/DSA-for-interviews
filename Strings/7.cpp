// Maximum Nesting Depth of the Parentheses

// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                cnt++;
                ans = max(ans,cnt);
            }
            else if(s[i] == ')'){
                cnt--;
            }
        }
        return ans;
    }
};