// Sqrt(x)

// Link: https://leetcode.com/problems/sqrtx/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long mid = s + (e-s )/2;
        int ans = -1;

        while(e>=s){
           long long  sq = mid * mid;

           if(sq == x)
           return mid;

           if(sq <x){
            ans = mid;
           s = mid +1;}

           else
           e = mid - 1;

           mid = s+(e-s)/2;}
       return ans;    
    }
};