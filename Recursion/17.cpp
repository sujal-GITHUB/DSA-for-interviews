// Letter Combinations of a Phone Number

// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, string& digits, string temp, unordered_map<char, vector<char>>& mpp, vector<string>& ans) {
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }

        for(char ch : mpp[digits[i]]){
            f(i+1, digits, temp+ch, mpp, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> mpp;
        mpp['2'] = {'a','b','c'};
        mpp['3'] = {'d','e','f'};
        mpp['4'] = {'g','h','i'};
        mpp['5'] = {'j','k','l'};
        mpp['6'] = {'m','n','o'};
        mpp['7'] = {'p','q','r','s'};
        mpp['8'] = {'t','u','v'};
        mpp['9'] = {'w','x','y','z'};

        vector<string> ans;
        if(digits.empty())
        return ans;

        string temp = "";
        f(0, digits, temp, mpp, ans);
        return ans;
    }
};
