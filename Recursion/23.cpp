// Sudoku Solver

// Link: https://leetcode.com/problems/sudoku-solver/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int i, int j, char val, vector<vector<char>>& board){
        for(int k=0; k<9; k++){
            if(board[i][k] == val)
            return false;

            if(board[k][j] == val)
            return false;

            int row = 3 * (i / 3) + k / 3;
            int col = 3 * (j / 3) + k % 3;
            if(board[row][col] == val)
            return false;
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isPossible(i, j, ch, board)){
                            board[i][j] = ch;

                            if(solve(board) == true)
                            return true;
                            else
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};