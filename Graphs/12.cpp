// Is Graph Bipartite?

// Link: https://leetcode.com/problems/is-graph-bipartite/description/

/*
# Quick rules to remember for coding:

Use 2-coloring DFS/BFS to check bipartiteness.

Check odd-length cycles → not bipartite.

Can have even-length cycles → still bipartite.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, 0);

        for(int i=0; i<n; i++){
            if(vis[i] != 0) 
            continue;

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                int nextvis = vis[node] == 1 ? 2 : 1;

                for(auto neighbor : graph[node]){
                    if(vis[neighbor] == 0) {
                        vis[neighbor] = nextvis;
                        q.push(neighbor);
                    }
                    else if(vis[neighbor] == vis[node]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};