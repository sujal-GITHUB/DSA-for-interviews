// Flood Fill

// Link: https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int old = image[sr][sc];
        if (old == color) 
        return image;  // Early return to avoid infinite loop

        queue<pair<int, int>> q;
        image[sr][sc] = color;

        q.push({sr, sc});
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == old) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};
