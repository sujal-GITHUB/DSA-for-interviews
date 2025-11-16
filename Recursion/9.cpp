// Count Good Numbers

// Link: https://leetcode.com/problems/count-good-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long a, long long b) {
        if(b == 0)
        return 1;

        long long temp = power(a, b/2);
        temp %= mod;

        if(!(b&1)){
            return temp*temp%mod;
        }
        else{
            return temp*temp*a%mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};
