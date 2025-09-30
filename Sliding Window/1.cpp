// Longest Substring Without Repeating Characters

// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                unordered_set<char> st(sub.begin(), sub.end());
                if (st.size() == sub.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};


// Approach 2

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>mpp;
        int l = 0;
        int len = 0;
        
        for(int r=0; r<n; r++){
            char ch = s[r];

            if(mpp.find(ch) != mpp.end() && mpp[ch] >= l){
                l = mpp[ch]+1;
            }

            mpp[ch] = r;
            
            len = max(len, r-l+1);
        }

        return len;
    }
};