// Shortest Path in Binary Matrix

// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) 
        return -1;

        vector<int> dr = {-1,-1,-1,0,0,1,1,1};
        vector<int> dc = {-1,0,1,-1,1,-1,0,1};

        vector<vector<int>>dist(m, vector<int>(n, 1e9));

        queue<pair<int , pair<int, int>>>q; //{wt, {x,y}}
        q.push({1, {0,0}});
        dist[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == m-1 && y == n-1){
                return d;
            }

            for(int i=0; i<8; i++){
                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0){
                    if(d + 1 < dist[nx][ny]){
                        dist[nx][ny] = d+1;
                        q.push({d+1, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};