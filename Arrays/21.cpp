// 3Sum

// Link: https://leetcode.com/problems/3sum/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1])
            continue;

            int k = i+1;
            int j = n-1;
            while(k < j){
                int sum = nums[k]+nums[j]+nums[i];

                if(sum == 0){
                    ans.push_back({nums[i], nums[k], nums[j]});

                    while (k < j && nums[k] == nums[k + 1]) k++;
                    while (k < j && nums[j] == nums[j - 1]) j--;
                    k++;
                    j--;
                }

                else if(sum > 0){
                    j--;
                }

                else{
                    k++;
                }
            }
        }
        return ans;
    }
};