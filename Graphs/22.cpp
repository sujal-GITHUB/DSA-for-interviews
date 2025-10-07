// Cheapest Flights Within K Stops

// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {     
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);

        while(!q.empty()){
            auto it=q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            if(stops > k)
            continue;
            
            for(auto kt: adj[node]){
                int adjNode = kt.first;
                int w = kt.second;

                if(cost+w<dist[adjNode] && stops<=k){
                    dist[adjNode] = cost + w;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }


        if(dist[dst] == 1e9)
        return -1;
        return dist[dst];
    }
};