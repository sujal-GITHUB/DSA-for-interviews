// N meetings in one room

// Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = end.size();
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++){
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), [&](auto a, auto b){
            if(a.second == b.second) 
            return a.first < b.first;
            
            return a.second < b.second;
        });
        
        int ans = 0;
        int last_end = -1e9;
        
        for(int i=0; i<n; i++){
            if(v[i].first > last_end){
                ans++;
                last_end = v[i].second;
            }
        }
        
        return ans;
    }
};