// Sort Colors

// Link: https://leetcode.com/problems/sort-colors/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};


// Approach 2

//Dutch National Flag Problem

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int k = 0;
        
        while(k <= j){
            if(nums[k] == 2){
                swap(nums[k], nums[j]);
                j--;
            }
            else if(nums[k] == 0){
                swap(nums[k], nums[i]);
                i++;
                k++;
            }
            else{
                k++;
            }
        }
    }
};
