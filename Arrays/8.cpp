// Majority Element

// Link: https://leetcode.com/problems/majority-element/description/

#include <bits/stdc++.h>
using namespace std;

//Boyer–Moore Majority Vote Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int el  = 0;

        for(int i=0; i<n; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(el == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        return el;
    }
};