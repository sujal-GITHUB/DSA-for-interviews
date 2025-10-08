// Next Permutation

// Link: https://leetcode.com/problems/next-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        //break pt;
        int idx  = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //find el
        for(int i=n-1; i>idx; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        reverse(nums.begin()+idx+1, nums.end());
    }
};