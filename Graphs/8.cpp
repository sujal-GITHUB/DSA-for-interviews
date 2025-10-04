// 01 Matrix

// Link: https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        
        // Push all 0s in queue as starting points
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(ans[nr][nc] > ans[r][c] + 1) { // relaxation
                        ans[nr][nc] = ans[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return ans;
    }
};
