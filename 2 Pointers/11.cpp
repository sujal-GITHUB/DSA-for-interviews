// Subarrays with K Different Integers

// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int f(vector<int>& nums, int k){
        int n = nums.size();
        if(k == 0)
        return 0;
        unordered_map<int, int>mp;

        int i = 0;
        int j = 0;
        int cnt = 0;

        while(j < n){
            mp[nums[j]]++;

            while(mp.size() > k){
                mp[nums[i]]--;

                if(mp[nums[i]] == 0)
                mp.erase(nums[i]);

                i++;
            }

            cnt += (j-i+1);
            j++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};