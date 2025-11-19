// Job Sequencing Problem

// Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        for (int i=0; i<n; i++){
            jobs.push_back({profit[i], deadline[i]});
        }

        sort(jobs.rbegin(), jobs.rend());
        int maxProfit = 0;
        int cnt = 0;
        int maxi = *max_element(deadline.begin(), deadline.end());
        
        vector<int>slot(maxi+1, -1);

        for(int i=0; i<n; i++){
            int d = min(maxi, jobs[i].second);
            
            for(; d>0; d--){
                if(slot[d] == -1){
                    slot[d] = i;
                    cnt++;
                    maxProfit += jobs[i].first;
                    break;
                }
            }
        }
        return {cnt, maxProfit};
    }
};

// Approach 2

class Solution {
public:
    int findp(int x, vector<int>& parent){
        if(parent[x] == x) 
        return x;

        return parent[x] = findp(parent[x], parent);
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({profit[i], deadline[i]});
        }

        sort(jobs.rbegin(), jobs.rend());
        int maxProfit = 0;
        int cnt = 0;
        int maxi = *max_element(deadline.begin(), deadline.end());

        vector<int> parent(maxi+1);

        for(int i=0; i<=maxi; i++) 
        parent[i] = i;

        for(int i=0; i<n; i++){
            int d = min(maxi, jobs[i].second);

            int avail = findp(d, parent);
            
            if(avail > 0){
                cnt++;
                maxProfit += jobs[i].first;
                parent[avail] = findp(avail-1, parent);
            }
        }

        return {cnt, maxProfit};
    }
};
