// Depth First Search

#include<bits/stdc++.h>
using namespace std;

/*
# Time Complexity:

Each vertex is visited once → O(V)

Each edge is explored once → O(E)

Total = O(V + E)

# Space Complexity:

visited[] array → O(V)

Recursion stack (in worst case, graph is a chain) → O(V)

Total = O(V)
*/

class Solution {
  public:
    void Dfs(int node, vector<vector<int>>& adj, vector<int>&ans, vector<int>&vis){
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                Dfs(it, adj, ans, vis);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int>ans;
        int n = adj.size();
        vector<int>vis(n, 0);
        
        Dfs(0, adj, ans, vis);
        return ans;
    }
};