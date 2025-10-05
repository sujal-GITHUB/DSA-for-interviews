// Course Schedule II

// Link: https://leetcode.com/problems/course-schedule-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int  n = prerequisites.size();
        unordered_map<int, int>indegree;
        vector<vector<int>>adj(numCourses);

        for(auto it: prerequisites){
            int v = it[0];
            int u = it[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            topo.push_back(node);

            for(auto n: adj[node]){
                indegree[n]--;
                if(indegree[n] == 0){
                    q.push(n);
                }
            }
        }

        return cnt == numCourses ? topo : vector<int>{};
    }
};