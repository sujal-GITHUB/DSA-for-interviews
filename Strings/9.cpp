// Longest Palindromic Substring

// Link: https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) 
        return "";

        int start = 0, maxLen = 1;

        for(int i = 0; i < n; i++){
            // Odd length palindrome
            int j = i, k = i;
            while(j >= 0 && k < n && s[j] == s[k]){
                if(k - j + 1 > maxLen){
                    maxLen = k - j + 1;
                    start = j;
                }
                j--;
                k++;
            }

            // Even length palindrome
            j = i, k = i + 1;
            while(j >= 0 && k < n && s[j] == s[k]){
                if(k - j + 1 > maxLen){
                    maxLen = k - j + 1;
                    start = j;
                }
                j--;
                k++;
            }
        }

        return s.substr(start, maxLen);
    }
};
