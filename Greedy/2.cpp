// Fractional Knapsack

// Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int, int>>v;
        for(int i=0; i<val.size(); i++){
            v.push_back({val[i], wt[i]});
        }
        
        sort(v.begin(), v.end(), [&](const auto a, const auto b){
            double x = (double)a.first / a.second;
            double y = (double)b.first / b.second;
            
            return x > y;
        });
        
        double ans = 0;
        for(auto it: v){
            if(capacity >= it.second){
                ans += it.first;
                capacity -= it.second;
            }
            else{
                ans += (double)it.first / it.second * capacity;
                break;
            }
        }
        
        return ans;
    }
};
