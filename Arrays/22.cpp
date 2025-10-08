// Largest subarray with 0 sum

// Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int>m;
        int prefixSum = 0;
        int maxLen = 0;

        for(int i=0; i<arr.size(); i++){
            prefixSum += arr[i];

            if(prefixSum == 0){
                maxLen = i+1; 
            }

            if(m.find(prefixSum) != m.end()){
                maxLen = max(maxLen, i - m[prefixSum]);
            } 
            else{
                m[prefixSum] = i;
            }
        }
        return maxLen;
    }
};