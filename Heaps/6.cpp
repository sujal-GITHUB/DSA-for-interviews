// Kth Largest Element in an Array

// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(auto it: nums){
            pq.push(it);
        }
        
        k--;
        while(k--){
            pq.pop();
        }

        return pq.top();
    }
};