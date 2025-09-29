// Maximum Points You Can Obtain from Cards

// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxSum = 0;

        // Try taking i cards from the left (0 to k)
        for (int i = 0; i <= k; i++) {
            int sum = 0;

            // Take first i cards from the left
            for (int l = 0; l < i; l++) {
                sum += cardPoints[l];
            }

            // Take remaining k-i cards from the right
            for (int r = 0; r < k - i; r++) {
                sum += cardPoints[n - 1 - r];
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};


// Approach 2

class Solution {
    public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i;
        int j = n-1;
        int lsum = 0;
        int rsum = 0;

        for(i=0; i<k; i++){
            lsum += cardPoints[i];
        }

        int maxSum = lsum;

        for (int i=1; i<=k; i++){
            lsum -= cardPoints[k-i];      
            rsum += cardPoints[n-i];  

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};