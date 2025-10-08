// Best Time to Buy and Sell Stock

// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i=0; i<n; i++){
            int profit = prices[i] - minPrice;

            maxProfit = max(profit, maxProfit);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};