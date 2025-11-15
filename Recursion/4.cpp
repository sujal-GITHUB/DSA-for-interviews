// Combination Sum - II

// Link: https://leetcode.com/problems/combination-sum-ii/description/

// TC = O(2^n × k)
// SC = O(m × k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, vector<int>&temp, int sum, vector<int>&candidates, vector<vector<int>>&ans, int target){
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        int n = candidates.size();
        if(i == n || sum > target)
        return;

        for(int j=i; j<n; j++){
            if(j>i && candidates[j] == candidates[j-1])
            continue;

            if(sum+candidates[i] > target)
            break;

            temp.push_back(candidates[j]);
            f(j+1, temp, sum+candidates[j], candidates, ans, target);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());

        f(0, temp, 0, candidates, ans, target);
        return ans;
    }
};