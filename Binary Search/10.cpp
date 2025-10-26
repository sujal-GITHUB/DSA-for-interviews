// Find Peak Element

// Link: https://leetcode.com/problems/find-peak-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if((mid-1 < 0 || nums[mid-1] < nums[mid]) &&
                (mid+1 >= n || nums[mid+1] < nums[mid])){
                    return mid;
            }

            if(mid>0 && nums[mid-1] > nums[mid]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};