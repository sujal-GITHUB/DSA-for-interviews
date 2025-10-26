// Reverse Words in a String

// Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    string reverseWords(string s) {
        vector<string>temp;
        string str = "";
        
        for(int i=0; i<=s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                if(!str.empty()){
                    temp.push_back(str);
                    str.clear();
                }
            }
            else{
                str += s[i];
            }
        }

        string ans = "";
        for(int i=temp.size()-1; i>0 ;i--){
            ans += temp[i];
            ans += ' ';
        }
        ans += temp[0];

        return ans;
    }
};

// Approach 2

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    st.push(word);
                    word.clear();
                }
            } else word += c;
        }
        if (!word.empty()) st.push(word);

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " ";
        }
        return ans;
    }
};
