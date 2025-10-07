// Minimum Multiplications to reach End

// Link: http://geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        vector<int>dist(100000,1e9);
        q.push({start,0});
        dist[start] = 0;
        int mod = 100000;
        
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for(auto it: arr){
                int num = (it*node) % mod;
                
                if(dis + 1 < dist[num])
                {
                    dist[num] = dis + 1;

                    if(num == end)
                    return dis+1;

                    q.push({num,dis+1});
                    
                }
            }
        }
        
        if(start==end) 
        return 0;

        return -1;
    }
};