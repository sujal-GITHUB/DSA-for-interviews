// Find Missing and Repeated Values

// Link: https://leetcode.com/problems/find-missing-and-repeated-values/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        long long expectedSum = 1LL*N*(N+1)/2;
        long long actualSum = 0;

        int repeated = -1;
        int missing = -1;
        vector<int>freq(N+1, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int val = grid[i][j];
                actualSum += val;
                freq[val]++;
                if(freq[val] == 2){
                    repeated = val;
                }
            }
        }
        missing = (int)(expectedSum - (actualSum - repeated));
        return {repeated, missing};
    }
};
