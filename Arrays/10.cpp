// Max Consecutive Ones

// Link: https://leetcode.com/problems/max-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxCnt = 0;
        while(i < n){
            int cnt = 0;
            while(i < n && nums[i] == 1){
                cnt++;
                i++;
            }
            maxCnt = max(cnt, maxCnt);
            i++;
        }        
        return maxCnt;
    }
};