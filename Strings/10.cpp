// Sum of Beauty of All Substrings

// Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {

public:   
    int beauty(vector<int>&f){
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0;i<26;i++){
            maxi = max(maxi,f[i]);
            if(f[i]>=1){
                mini = min(mini,f[i]);
            }
        }
        return maxi - mini;
    }

    int beautySum(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++){
            vector<int>map(26,0);
            for(int j=i;j<s.size();j++){
                map[s[j]-'a']++;
                res += beauty(map);
            }     
        }
        return res;
    }
};