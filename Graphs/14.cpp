// Course Schedule

// Link: https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& v) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);

        for(auto it: v){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return cnt == numCourses;
    }
};