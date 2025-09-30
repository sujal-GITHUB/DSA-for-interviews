// Find Kth Rotation

// Link: https://www.geeksforgeeks.org/problems/rotation4723/1

#include <bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int>& arr){
    int n = arr.size();
    int l = 0, r = n-1;

    while(l <= r){
        // If subarray is already sorted
        if(arr[l] <= arr[r]) 
            return l;

        int mid = l + (r-l)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;

        // Check if mid is minimum
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return mid;

        // Decide which half to go
        if(arr[mid] >= arr[l]) // left half sorted, go right
            l = mid+1;
        else // right half sorted, go left
            r = mid-1;
    }

    return 0; // fallback, array not rotated
}