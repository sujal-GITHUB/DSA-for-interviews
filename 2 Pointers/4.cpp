// Longest Repeating Character Replacement

// Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> freq(26, 0);
                for (int x = i; x <= j; x++) 
                freq[s[x]-'A']++;

                int maxFreq = *max_element(freq.begin(), freq.end());
                
                if ((j - i + 1) - maxFreq <= k) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};


// Approach 2

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        unordered_map<char, int>mpp;
        int maxFreq = INT_MIN;
        int ans = 0;

        for(int r=0; r<n; r++){
            char ch = s[r];
            mpp[ch]++;

            maxFreq = max(maxFreq, mpp[ch]);

            while((r-l+1)-maxFreq > k){
                mpp[s[l]]--;

                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};