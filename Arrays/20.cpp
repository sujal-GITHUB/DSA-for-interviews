// Majority Element II

// Link: https://leetcode.com/problems/majority-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int el1 = -1, el2 = -1;

        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else cnt1--, cnt2--;
        }

        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }

        vector<int> res;
        if(cnt1 > n / 3) res.push_back(el1);
        if(cnt2 > n / 3) res.push_back(el2);
        return res;
    }
};
