// Find Eventual Safe States

// Link: https://leetcode.com/problems/find-eventual-safe-states/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indegree(n,0);
        vector<int>revAdj[n];

        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        vector<int>safe;

        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: revAdj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                q.push(it);
            }
        }

        sort(safe.begin(),safe.end());
        return safe;
    }
};