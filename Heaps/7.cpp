// Nearly sorted or Sort k sorted array

// Link: https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        int j = 0;
        
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            
            if(pq.size() > k){
                arr[j] = pq.top();
                pq.pop();
                j++;
            }
        }
        
        while(pq.size() !=0 ){
            arr[j] = pq.top();
            pq.pop();
            j++;
        }
    }
};