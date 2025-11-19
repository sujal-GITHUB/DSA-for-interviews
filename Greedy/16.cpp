// Non-overlapping Intervals

// Link: https://leetcode.com/problems/non-overlapping-intervals/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b){
            if(a[1] == b[1])
            return a[0] < b[0];

            return a[1] < b[1];
        });

        int e = INT_MIN;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(e <= intervals[i][0]){
                cnt++;
                e = intervals[i][1];
            }
        }

        return n-cnt;
    }
};