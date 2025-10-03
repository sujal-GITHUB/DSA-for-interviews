// Breadth First Search

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        queue<int>q;
        q.push(0);
        vector<int>ans;
        
        vector<int>vis(n, 0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};