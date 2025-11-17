// Generate all binary strings

// Link: https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void f(int i, vector<string>&ans, int n, string temp){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        
        // Pick 0
        f(i+1, ans, n, temp+'0');
        
        // Pick 1
        f(i+1, ans, n, temp+'1');
    }
  
    vector<string> binstr(int n) {
        vector<string>ans;
        f(0, ans, n, "");
        return ans;
    }
};