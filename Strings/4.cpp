// Isomorphic Strings

// Link: https://leetcode.com/problems/isomorphic-strings/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m)
        return false;

        unordered_map<char, char>m1, m2;
        for(int i=0; i<n; i++){
            char c1 = s[i];
            char c2 = t[i];

            if((m1.count(c1) && m1[c1] != c2) || (m2.count(c2) && m2[c2] != c1)){
                return false;
            }

            m1[c1] = c2;
            m2[c2] = c1;
        }
        return true;
    }
};

// Approach 2

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> m1(256, -1), m2(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (m1[s[i]] != m2[t[i]]) 
            return false;

            m1[s[i]] = m2[t[i]] = i;
        }
        return true;
    }
};
