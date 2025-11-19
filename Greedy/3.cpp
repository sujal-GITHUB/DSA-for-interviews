// Minimum number of Coins

// Link: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(int n) {
        vector<int>v = {10 , 5, 2 , 1};
        int cnt = 0;
        int i = 0;
        
        while(n > 0){
            if(n >= v[i]){
                cnt += n / v[i];
                n = n % v[i];
            }
            
            i++;
        }
        
        return cnt;
    }
};