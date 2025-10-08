// Merge Intervals

// Link: https://leetcode.com/problems/merge-intervals/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;

        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            vector<int>&last = ans.back();

            int s = intervals[i][0];
            int e = last[1];

            if(s <= e){
                last[1] = max(last[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};