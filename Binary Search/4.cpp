// Find First and Last Position of Element in Sorted Array

// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstPos(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1, ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                ans = mid;
                r = mid - 1;
            }

            else if(nums[mid] < target) 
            l = mid + 1;

            else 
            r = mid - 1;
        }
        return ans;
    }

    int lastPos(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1, ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                ans = mid;
                l = mid + 1;
            }

            else if(nums[mid] < target) 
            l = mid + 1;

            else 
            r = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPos(nums, target);
        int last = lastPos(nums, target);
        return {first, last};
    }
};
