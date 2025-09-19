// Missing Number

// Link: https://leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int actual = n*(n+1)/2;
        return actual-sum;
    }
};