// Two Sum

// Link: https://leetcode.com/problems/two-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        unordered_map<int, int> m;
        for (int i = 0; i < a.size(); ++i) {
            int x = t - a[i];
            if (m.count(x)) return {m[x], i};
            m[a[i]] = i;
        }
        return {};
    }
};

// Approach 2

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int one = 0, second = 1;

        while (one < n - 1) {
            if (nums[one] + nums[second] == target) {
                return {one, second};
            }
            else {
                if (second < n-1) {
                    second++;
                } 
                else {
                    one++;
                    second = one + 1;
                }
            }
        }

        return {};
    }
};
