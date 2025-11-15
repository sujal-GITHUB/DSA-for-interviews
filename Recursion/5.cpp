// Palindrome Partitioning

// Link: https://leetcode.com/problems/palindrome-partitioning/description/

// TC: O(2^n)
// SC = O(k) (recursion stack + temp array) + O(number_of_combinations * k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        int i = 0;
        int j = n-1;

        if(n == 0)
        return true;

        while(i<=j){
            if(s[i] != s[j])
            return false;

            i++;
            j--;
        }
        return true;
    }

    void f(int i, vector<string>&temp, string s, vector<vector<string>>&ans){
        int n = s.size();
        if(i == n){
            ans.push_back(temp);
            return;
        }

        for(int j=i; j<n; j++){
            string sub = s.substr(i, j-i+1);
            if(isPalindrome(sub)){
                temp.push_back(sub);
                f(j+1, temp, s, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>temp;

        f(0, temp, s, ans);
        return ans;
    }
};