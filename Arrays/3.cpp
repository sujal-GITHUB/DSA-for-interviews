// Rotate Array

// Link: https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        //reverse the array
        reverse(nums.begin(), nums.end());

        //reverse by k steps
        reverse(nums.begin(), nums.begin()+k);

        //reverse remaining
        reverse(nums.begin()+k, nums.end());
    }
};