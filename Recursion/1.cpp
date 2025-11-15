// Subset Sums

// Link: http://geeksforgeeks.org/problems/subset-sums2234/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void f(int i, vector<int>&ans ,vector<int>& arr, int sum){
        int n = arr.size();
        if(i == n){
            ans.push_back(sum);
            return;
        }
        
        f(i+1, ans, arr, sum);
        f(i+1, ans, arr, sum+arr[i]);
    }
  
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>ans;
        f(0, ans, arr, 0);
        return ans;
    }
};