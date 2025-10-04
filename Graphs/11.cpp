// Word Ladder

// Link: https://leetcode.com/problems/word-ladder/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        bool found = false;
        for(int i=0; i<n; i++){
            if(endWord == wordList[i])
            found = true;
        }

        if(!found)
        return 0;

        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;

        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int l = q.front().second;
            q.pop();

            if(word == endWord)
            return l;

            for(int k=0; k<word.size(); k++){
                char original = word[k];

                for(char i = 'a' ; i <= 'z' ; i++){
                    word[k] = i;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, l+1});
                    }
                }

                word[k] = original;
            }
        }
        return 0;
    }
};