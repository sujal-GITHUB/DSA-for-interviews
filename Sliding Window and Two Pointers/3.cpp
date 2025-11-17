// Fruit Into Baskets

// Link: https://leetcode.com/problems/fruit-into-baskets/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_set<int> st;
                for (int k = i; k <= j; k++) {
                    st.insert(fruits[k]);
                }
                if (st.size() <= 2) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};


// Approach 2

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int>mpp;
        int l = 0;
        int maxF = 0;

        for(int r=0; r<n; r++){
            mpp[fruits[r]]++;

            while(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }

                l++;
            }

            maxF = max(maxF, r-l+1);
        }
        return maxF;
    }
};