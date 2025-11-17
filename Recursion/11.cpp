// Reverse a Stack

// Link: https://www.geeksforgeeks.org/problems/reverse-a-stack/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
  public:
    void reverseStack(stack<int> &st) {
        if(st.empty()) 
        return;

        int x = st.top();
        st.pop();

        reverseStack(st);

        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }

        st.push(x);

        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};

// Approach 2

class Solution {
  public:
    void insertBottom(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int y = st.top();
        st.pop();
        insertBottom(st, x);
        st.push(y);
    }
  
    void reverseStack(stack<int> &st) {
        if(st.empty()) 
        return;
        
        int x = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertBottom(st, x);
    }
};