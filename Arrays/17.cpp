// Set Matrix Zeroes

// Link: https://leetcode.com/problems/set-matrix-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>r(row,0);
        vector<int>c(col,0);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(r[i] == 1 || c[j] == 1)
                matrix[i][j] = 0;
            }
        }
    }
};