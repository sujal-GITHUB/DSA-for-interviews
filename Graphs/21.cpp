// Path With Minimum Effort

// Link: https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, 0}});

        vector<vector<int>>minEffort(m, vector<int>(n, 1e9));
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!pq.empty()){
            auto it = pq.top();
            int effort = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();

            if(x == m-1 && y == n-1){
                return effort;
            }

            for(int k=0; k<4; k++){
                int nr = x + dr[k];
                int nc = y + dc[k];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int newEffort = max(effort, abs(heights[x][y] - heights[nr][nc]));
                    if(newEffort < minEffort[nr][nc]){
                        minEffort[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};