// Network Delay Time

// Link: https://leetcode.com/problems/network-delay-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        pq.push({0, k});
        vector<int>time(n+1, 1e9);
        time[k] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int t = it.first;
            int node = it.second;

            if(t > time[node]) 
            continue;

            for(auto x: adj[node]){
                int newT = t + x.second;

                if(newT < time[x.first]){
                    time[x.first] = newT;
                    pq.push({newT, x.first});
                }
            }
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(time[i] == 1e9) 
            return -1;

            ans = max(ans, time[i]);
        }
        return ans;
    }
};