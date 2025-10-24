// Rotate Image

// Link: https://leetcode.com/problems/rotate-image/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};