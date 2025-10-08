// Longest Consecutive Sequence

// Link: https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;

        for(int x: st){
            if(st.find(x-1) == st.end()){
                int cnt = 1;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    x++;
                }
                maxLen = max(maxLen, cnt);
            }
        }

        return maxLen;
    }
};
