// Partitions with Given Difference

// Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

using ll = long long;

class Solution {
  public:
    int f(int i, vector<int>&arr, int t, vector<vector<int>>&dp){
        int n = arr.size();
        if(i == n){
            if(t == 0)
            return 1;
            else
            return 0;
        }
        
        if(dp[i][t] != -1)
        return dp[i][t];
        
        // Leave
        int not_pick = f(i+1, arr, t, dp);
        
        // Pick
        int pick = 0;
        if(arr[i] <= t){
            pick = f(i+1, arr, t-arr[i], dp);
        }
        
        return dp[i][t] = pick + not_pick;
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        ll sum = 0;
        
        for(auto c: arr)
        sum += c;
        
        // s1 - s2 = diff
        // s1 + s2 = sum
        // 2*s1 = diff + sum
        // s1 = (diff + sum)/2
        
        if(diff > sum)
        return 0;
        
        ll s = sum + diff;
        if(s&1)
        return 0;
        
        int target = s/2;
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        
        return f(0, arr, target, dp);
    }
};

// Tabulation

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        long long sum = 0;
        int n = arr.size();

        for(int x: arr) 
        sum += x;

        if(diff > sum) 
        return 0;

        long long s = sum + diff;

        if(s % 2) 
        return 0;
        
        int target = (int)(s/2);

        const long long MOD = 1000000007;
        vector<long long> dp(target+1, 0);

        dp[0] = 1;

        for(int num: arr){
            for(int t = target; t >= num; t--){
                dp[t] = (dp[t] + dp[t-num]) % MOD;
            }
        }
        return (int)dp[target];
    }
};
