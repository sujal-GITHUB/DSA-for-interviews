// Binary Search

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>v, int x){
    int n = v.size();

    int l = 0;
    int r = n-1;

    while(l <= r){
        int mid = l + (r-l)/2;

        if(v[mid] == x)
        return mid;

        else if(v[mid] < x){
            l = mid+1;
        }

        else{
            r = mid-1;
        }
    }

    return -1;
}