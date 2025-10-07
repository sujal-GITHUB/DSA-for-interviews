// Number of Ways to Arrive at Destination

// Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,LONG_MAX);
        vector<long long>ways(n,0);

        dist[0] = 0;
        ways[0] = 1;
        int mod = (long long)(1e9+7);

        while(!pq.empty()){
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                long long adjNode = it.first;
                long long w = it.second;

                if(dis+w < dist[adjNode]){
                    dist[adjNode] = dis + w;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }

                else if(dis+w == dist[adjNode]){
                    ways[adjNode] = (ways[node] + ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};