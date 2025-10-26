// Rotate String

// Link: https://leetcode.com/problems/rotate-string/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    bool rotateString(string s, string goal){
        int n = s.size();
        int m = goal.size();

        if(n != m)
        return false;

        s += s;
        int i = 0;
        while(i<n){
            if(s[i] == goal[i]){
                break;
            }
            i++;
        }

        int j = 0;
        while(i < n){
            if(s[i] != goal[j])
            return false;
            i++;
            j++;
        }

        return true;
    }
};