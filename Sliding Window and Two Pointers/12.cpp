// Number of Subsequences That Satisfy the Given Sum Condition

// Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int n = nums.size();
        int res = 0;

        sort(nums.begin(), nums.end());
        vector<int>powr(n, 1);
        for(int i=1; i<n; i++){
            powr[i] = (powr[i-1]*2LL)%mod;
        }

        int i=0;
        int j=n-1;

        while(i<=j){
            if(nums[i]+nums[j] <= target){
                int diff = j-i;
                res = (res%mod + powr[diff]%mod)%mod;
                i++;
            }
            else{
                j--;
            }
        }

        return res;
    }
};
