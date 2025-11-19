// Shortest Job first

// Link: https://www.geeksforgeeks.org/problems/shortest-job-first/1

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        vector<int>burst = bt;

        sort(burst.begin(), burst.end());

        long long totalWait = 0;
        long long currTime = 0;

        for(int i = 0; i < n; i++){
            totalWait += currTime;
            currTime += burst[i];
        }

        return totalWait / n;
    }
};
