// Jump Game II

// Link: https://leetcode.com/problems/jump-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1)
        return 0;

        int f = 0;
        int jumps = 0;
        int end = 0;

        for(int i=0; i<n-1; i++){
            f = max(f, i+nums[i]);

            if(i == end){
                jumps++;
                end = f;
            }
        }
        return jumps;
    }
};