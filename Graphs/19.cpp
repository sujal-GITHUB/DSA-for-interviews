// Dijkstra Algorithm

// Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int>dist(V, 1e9);
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({w, v});
        }
        
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            for(auto x: adj[node]){
                int edW = x.first;
                int adN = x.second;
                
                if(wt+edW < dist[adN]){
                    dist[adN] = wt+edW;
                    pq.push({dist[adN], adN});
                } 
            }
        }
        
        return dist;
    }
};