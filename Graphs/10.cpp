// Number of Enclaves

// Link: https://leetcode.com/problems/number-of-enclaves/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis ,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k=0; k<4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, vis, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, vis, grid);
            }
        }

        for(int i=0; i<m; i++){
            if(grid[i][n-1] == 1){
                dfs(i, n-1, vis, grid);
            }
        }

        for(int j=0; j<n; j++){
            if(grid[0][j] == 1){
                dfs(0, j, vis, grid);
            }
        }

        for(int j=0; j<n; j++){
            if(grid[m-1][j] == 1){
                dfs(m-1, j, vis, grid);
            }
        }

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }

        return ans;
    }
};