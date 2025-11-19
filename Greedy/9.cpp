// Minimum Platforms

// Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Brute Force

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int need = 1;
            for(int j=0;j<n;j++){
                if(i==j) 
                continue;

                if(!(dep[j] < arr[i] || arr[j] > dep[i])) 
                need++;
            }
            ans = max(ans, need);
        }
        return ans;
    }
};

// Greedy
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