// Kth Largest Element in a Stream

// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k_, vector<int>& nums) {
        k = k_;
        for(int n: nums){
            pq.push(n);
            if(pq.size() > k) 
            pq.pop();
        }
    }

    int add(int val){
        pq.push(val);
        if(pq.size() > k) 
        pq.pop();
        
        return pq.top();
    }
};
