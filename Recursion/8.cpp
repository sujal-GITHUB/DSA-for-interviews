// Pow(x, n)

// Link: https://leetcode.com/problems/powx-n/description/

// Binary Exponentiation
// TC : O(log|n|)
// SC : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double f(double x, long long n) {
        if(n == 0)
        return 1;

        double temp = f(x, n/2);
        if(!(n&1))
            return temp * temp;
        else
            return temp * temp * x;
    }

    double myPow(double x, int n) {
        long long nn = n; 
        if(nn < 0) {
            x = 1 / x;
            nn = -nn;
        }
        return f(x, nn);
    }
};