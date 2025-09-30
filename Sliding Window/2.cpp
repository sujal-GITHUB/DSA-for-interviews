// Max Consecutive Ones III

// Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) 
                zeros++;

                if (zeros <= k) 
                ans = max(ans, j - i + 1);
                
                else break;
            }
        }
        return ans;
    }
};


// Approach 2

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int zeros = 0;
        int ans = 0;

        for(int r=0; r<n; r++){
            if(nums[r] == 0)
            zeros++;

            while(zeros > k){
                if(nums[l] == 0)
                zeros--;

                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};