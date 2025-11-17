// M-Coloring Problem

// Link: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canColor(int i, vector<vector<int>>&adj, int c, vector<int>&color){
        for(auto it: adj[i]){
            if(color[it] == c)
            return false;
        }
        
        return true;
    }
  
    bool f(int i, vector<vector<int>>&adj, int m, vector<int>&color){
        int n = adj.size();
        if(i == n){
            return true;
        }
        
        for(int k=1; k<=m; k++){
            if(canColor(i, adj, k, color)){
                color[i] = k;
                if(f(i+1, adj, m, color))
                return true;
                color[i] = 0;
            }            
        }
        
        return false;
    }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int>color(v, 0);
        vector<vector<int>>adj(v);
        for(auto it: edges){
            int i = it[0];
            int j = it[1];
            
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        
        return f(0, adj, m, color);
    }
};