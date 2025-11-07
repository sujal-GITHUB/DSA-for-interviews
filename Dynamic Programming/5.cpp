// Ninja’s Training

// Link: http://naukri.com/code360/problems/ninja-s-training_3621003

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization

int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    int n = points.size();
    if (day == n) return 0;

    if (dp[day][last + 1] != -1) return dp[day][last + 1];

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int val = points[day][task] + f(day + 1, task, points, dp);
            maxi = max(maxi, val);
        }
    }
    return dp[day][last + 1] = maxi;
}

int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(0, -1, points, dp);
}


// Tabulation

int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case for day 0
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    // Fill DP table
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int val = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], val);
                }
            }
        }
    }

    return dp[n - 1][3];
}