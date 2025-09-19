// Subarray Sum Equals K

// Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        int sum = 0;
        int ans = 0;
        mpp[0] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];

            if(mpp.find(sum-k) != mpp.end()){
                ans += mpp[sum-k];
            }

            mpp[sum]++;
        }

        return ans;
    }
};