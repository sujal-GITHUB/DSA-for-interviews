// Count Subarrays with given XOR

// Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<long , int>mpp;
        long cnt = 0;
        long pXor = 0; 
        mpp[0] = 1;
        
        for(int i=0; i<n; i++){
            pXor ^= arr[i];
            long x = pXor^k;
            
            if(mpp.find(x) != mpp.end()){
                cnt += mpp[x];
            }
            
            mpp[pXor]++;
        }
        
        return cnt;
    }
};