// Breadth First Search

#include<bits/stdc++.h>
using namespace std;

/*
# Time Complexity:

Each vertex is visited once → O(V)

Each edge is traversed once → O(E)

Total = O(V + E)

# Space Complexity:

visited[] array → O(V)

Queue for BFS → O(V) (worst case, all vertices in queue)

Total = O(V)
*/

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