// Binary Subarrays With Sum

// Link: https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == goal) 
                ans++;
            }
        }
        return ans;
    }
};

// Approach 2

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal-1);
    }

    int f(vector<int>& nums, int goal){
        int n = nums.size();
        int l = 0;

        if(goal < 0)
        return 0;

        int sum = 0;
        int ans = 0;

        for(int r=0; r<n; r++){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            ans += (r-l+1);
        }

        return ans;
    }
};