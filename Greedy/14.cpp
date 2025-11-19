// Insert Interval

// Link: https://leetcode.com/problems/insert-interval/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        int ns = newInterval[0];
        int ne = newInterval[1];

        // add intervals before newInterval
        while(i < n && intervals[i][1] < ns){
            ans.push_back(intervals[i]);
            i++;
        }

        // merge overlapping intervals
        while(i < n && intervals[i][0] <= ne){
            ns = min(ns, intervals[i][0]);
            ne = max(ne, intervals[i][1]);
            i++;
        }
        ans.push_back({ns, ne});

        // add remaining intervals
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
