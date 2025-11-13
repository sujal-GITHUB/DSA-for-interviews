// Does array represent Heap

// Link: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        for(int i=0; i<n/2; i++){
            int l = 2*i + 1; 
            int r = 2*i + 2;
            
            if(l<=n && arr[l]>arr[i])
            return false;
            
            if(r<=n && arr[r]>arr[i])
            return false;
            
        }
        return true;
    }
};