// Combination Sum III

// Link: https://leetcode.com/problems/combination-sum-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, vector<int>&temp, vector<vector<int>>&ans, int k, int n){
        if(n == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }

        if(i > 9)
        return;

        if(temp.size() > k)
        return;

        temp.push_back(i);
        f(i+1, temp, ans, k, n-i);
        temp.pop_back();
        f(i+1, temp, ans, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(1, temp, ans, k, n);

        return ans;
    }
};