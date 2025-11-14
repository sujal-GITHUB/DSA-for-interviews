// Minimum Cost of ropes

// Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(auto c: arr){
            pq.push(c);
        }
        
        int ans = 0;
        
        while(pq.size() > 1){
            int fir = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            
            int sum = fir+sec;
            ans += sum;
            pq.push(sum);
        }
        
        return ans;
    }
};