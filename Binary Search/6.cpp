// Search in Rotated Sorted Array II

// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target)
            return true;

            if(nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
            }
            else if(nums[mid] >= nums[l]){
                if(nums[l] <= target && nums[mid] >= target){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && nums[r] >= target){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return false;
    }
};