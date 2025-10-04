// Surrounded Regions

// Link: https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>&board){
        vis[r][c] = 1;

        int m = board.size();
        int n = board[0].size();

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O' && !vis[nr][nc]){
                dfs(nr, nc, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>vis(m, vector<int>(n, 0));

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && !vis[0][j]) 
            dfs(0, j, vis, board);

            if(board[m-1][j] == 'O' && !vis[m-1][j]) 
            dfs(m-1, j, vis, board);
        }

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !vis[i][0]) 
            dfs(i, 0, vis, board);

            if(board[i][n-1] == 'O' && !vis[i][n-1]) 
            dfs(i, n-1, vis, board);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};