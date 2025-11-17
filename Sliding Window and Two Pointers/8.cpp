// Number of Substrings Containing All Three Characters

// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            unordered_set<char> st;
            for(int j = i; j < n; j++){
                st.insert(s[j]);
                if(st.size() == 3) ans++;
            }
        }
        return ans;
    }
};

// Approach 2

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int>mpp;
        int l = 0;
        int ans = 0;

        for(int r=0; r<n; r++){
            mpp[s[r]]++;

            while(mpp['a'] >= 1 && mpp['b'] >=1 && mpp['c'] >= 1){
                mpp[s[l]]--;
                l++;

                ans += n-r;
            } 
        }
        return ans;
    }
};