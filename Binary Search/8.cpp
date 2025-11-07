// Find Kth Rotation

// Link: https://www.geeksforgeeks.org/problems/rotation4723/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int mini = 0;
        int smallest = 1e9;
        
        int l = 0;
        int r = n-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[l] <= arr[mid]){
                if(arr[l] <= smallest){
                    mini = l;
                    smallest = arr[l];
                }
                l = mid+1;
            }
            else{
                if(arr[mid] <= smallest){
                    mini = mid;
                    smallest = arr[mid];
                }
                r = mid-1;
            }
        }
        
        return mini;
    }
};
