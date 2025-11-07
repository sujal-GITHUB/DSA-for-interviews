// Sort Characters By Frequency

// Link: https://leetcode.com/problems/sort-characters-by-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c: s){
            freq[c]++;
        }

        vector<pair<char, int>>vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string result = "";
        for(auto &p: vec) {
            result.append(p.second, p.first); 
        }

        return result;
    }
};