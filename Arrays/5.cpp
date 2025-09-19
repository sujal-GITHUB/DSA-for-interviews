// Union of 2 Sorted Arrays

// Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                if (ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
                i++;
            }
            else if (b[j] < a[i]) {
                if (ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
                j++;
            }
            else { // a[i] == b[j]
                if (ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        
        while (i < n) {
            if (ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++;
        }
        
        while (j < m) {
            if (ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
            j++;
        }
        
        return ans;
    }
};
