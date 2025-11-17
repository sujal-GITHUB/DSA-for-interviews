// Sort a stack

// Link: http://geeksforgeeks.org/problems/sort-a-stack/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
  public:
    void sortStack(stack<int> &st) {
        vector<int>v;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            v.push_back(top);
        }
        
        sort(v.begin(), v.end());
        for(auto c: v){
            st.push(c);
        }
    }
};

// Approach 2

class Solution {
  public:
    void insertInSortedPos(stack<int> &st, int x){
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }
        
        int y = st.top();
        st.pop();
        
        insertInSortedPos(st, x);
        
        st.push(y);
    }
  
    void sortStack(stack<int> &st) {
        if(st.empty())
        return;
        
        int x = st.top();
        st.pop();
        
        sortStack(st);
        
        insertInSortedPos(st, x);
    }
};
