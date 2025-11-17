// N - Queens

// Link: https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, vector<string>&board){
        int n = board.size();

        // Up
        for(int k=i-1; k>=0; k--){
            if(board[k][j] == 'Q')
            return false;
        }

        // Left Diagonal
        for(int k=j-1, m=i-1; k>=0 && m>=0; k--, m--){
            if(board[m][k] == 'Q')
            return false;
        }

        // Right Diagonal
        for(int k=j+1, m=i-1; k<n && m>=0; k++, m--){
            if(board[m][k] == 'Q')
            return false;
        }

        return true;
    }

    void f(int i, int n, vector<vector<string>>&ans, vector<string>&board){
        if(i >= n){
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(isValid(i, j, board)){
                board[i][j] = 'Q';

                f(i+1, n, ans, board);

                board[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        f(0, n, ans, board);
        return ans;
    }
};