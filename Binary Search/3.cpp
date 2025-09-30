// Implement Upper Bound

// Link: https://www.geeksforgeeks.org/problems/implement-upper-bound/1

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> v, int x){
    int n = v.size();
    int l = 0, r = n-1;
    int ans = n;

    while(l <= r){
        int mid = l + (r-l)/2;

        if(v[mid] > x){
            ans = mid; 
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}