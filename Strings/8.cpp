// Count Number of Homogenous Substrings

// Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int mod = 1e9+7;

    int countHomogenous(string s) {
        int n = s.size();
        long long ans = 0;

        for(int i=0; i<n;){
            long long cnt = 0;
            char ch = s[i];
            while(i<n && s[i] == ch){
                cnt++;
                i++;
            }

            ans = (ans + (cnt*(cnt+1)/2)%mod)%mod;
        }
        return (int)ans;
    }
};