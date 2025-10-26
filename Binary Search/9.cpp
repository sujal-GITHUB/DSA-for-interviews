// Single Element in a Sorted Array

// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            // Make sure mid is even so it points to the first element of a pair
            if (mid % 2 == 1)
            mid--;

            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2; // Move right
            } else {
                r = mid; // Move left, including mid
            }
        }
        return nums[l];
    }
};
