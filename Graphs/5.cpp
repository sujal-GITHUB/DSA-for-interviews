// Rotting Oranges

// Link: https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m, vector<int>(n, 0));
        int fresh = 0;
        queue<pair<int, pair<int, int>>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({0, {i,j}});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1){
                    fresh++;
                    vis[i][j] = 1;
                }
            }
        } 

        if(fresh == 0)
        return 0;

        int minTime = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int t = it.first;
            int x = it.second.first;
            int y = it.second.second;

            minTime = max(minTime, t);

            int dr[] = {0, 0, -1, 1};
            int dc[] = {-1, 1, 0, 0};

            for(int i=0; i<4; i++){
                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] == 1){
                    vis[nx][ny] = 2;
                    fresh--;
                    q.push({t+1, {nx, ny}});
                }
            }
        }

        if(fresh > 0)
        return -1;

        return minTime;
    }
};