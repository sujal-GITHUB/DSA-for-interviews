// Maximum Sum Combination

// Link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = b.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        priority_queue<pair<int, pair<int, int>>>pq;
        set<pair<int, int>>st;
        
        pq.push({a[0]+b[0], {0,0}});
        st.insert({0,0});
        vector<int>ans;
        
        while(ans.size() < k){
            auto it = pq.top();
            pq.pop();
            
            int s = it.first;
            int i = it.second.first;
            int j = it.second.second;
            
            ans.push_back(s);
            
            if(i+1 < n && (st.find({i+1, j}) == st.end())){
                pq.push({a[i+1]+b[j], {i+1,j}});
                st.insert({i+1,j});
            }
            
            if(j+1 < n && (st.find({i, j+1}) == st.end())){
                pq.push({a[i]+b[j+1], {i,j+1}});
                st.insert({i,j+1});
            }
        }
        
        return ans;
    }
};