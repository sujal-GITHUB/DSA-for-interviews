// Word Search

// Link: http://leetcode.com/problems/word-search/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int k, vector<vector<bool>>&visited){
        int m = board.size();
        int n = board[0].size();

        if(k == word.size())
        return true;

        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[k])
        return false;

        visited[i][j] = true;
        bool found = dfs(i+1, j, board, word, k+1, visited) ||
        dfs(i, j+1, board, word, k+1, visited) ||
        dfs(i-1, j, board, word, k+1, visited) ||
        dfs(i, j-1, board, word, k+1, visited);

        visited[i][j] = false; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i, j, board, word, 0, visited))
                    return true;
                }
            }
        }

        return false;
    }
};