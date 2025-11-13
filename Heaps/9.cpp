// Rank Transform of an Array

// Link: https://leetcode.com/problems/rank-transform-of-an-array/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
        return {};

        vector<int>brr = arr;
        sort(brr.begin(), brr.end());

        unordered_map<int,int>rank;
        int r=1;

        for(int x : brr){
            if(!rank.count(x)) 
            rank[x] = r++;
        }

        for(int i = 0; i < n; i++)
        arr[i] = rank[arr[i]];

        return arr;
    }
};

// Approach 2

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
        return {};

        priority_queue<int, vector<int>, greater<int>>pq;
        unordered_map<int, int>mpp;

        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }

        unordered_map<int,int>mp;
        int r = 1;
        while(!pq.empty()){
            int v = pq.top(); 
            pq.pop();

            if(mp.find(v) == mp.end()) 
            mp[v] = r++;
        }

        for(int i=0; i<n; i++) 
        arr[i] = mp[arr[i]];

        return arr;
    }
};
