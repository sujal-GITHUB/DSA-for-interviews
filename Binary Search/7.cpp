// Find Minimum in Rotated Sorted Array

// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = 0;
        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l <= r){ 
            int mid = l + (r-l)/2;

            if(nums[mid] < nums[0]){
                mini = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return nums[mini];
    }
};