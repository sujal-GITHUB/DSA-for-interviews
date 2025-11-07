// Longest Common Prefix

// Link: https://leetcode.com/problems/longest-common-prefix/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";

        for(int i=0;i<strs[0].size(); i++){
            char ch = strs[0][i];
            bool match = true;

            for(int j=1;j<n;j++){
                if(strs[j].size()<i || strs[j][i]!=ch){
                    match = false;
                    break;
                }
            }
            if(match == false) {break;}
            else {ans.push_back(ch);}
        }
        return ans;
    }
};

// Approach 2

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());

        string ans = "";
        for(int i=0; i<strs[0].size(); i++){
            if(strs[0][i] != strs[n-1][i]){
                break;
            }

            ans += strs[0][i];
        }

        return ans;
    }
};