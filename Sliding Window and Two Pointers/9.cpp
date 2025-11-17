// Count Number of Nice Subarrays

// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int oddCount = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] & 1) 
                oddCount++;

                if (oddCount == k) 
                ans++;
                
                else if (oddCount > k) 
                break;
            }
        }

        return ans;
    }
};


// Approach 2

class Solution {
public:
    int f(vector<int>& nums, int k){
        int n = nums.size();
        int ans = 0;
        int odds = 0;

        int i = 0;
        int j = 0;

        while(j<n){
            if(nums[j]&1)
            odds++;

            while(odds > k){
                if(nums[i]&1)
                odds--;

                i++;
            }

            ans += (j-i+1);
            j++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};