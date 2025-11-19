// Minimum Platforms

// Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Brute Force

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int need = 1;
            for(int j=0;j<n;j++){
                if(i==j) 
                continue;

                if(!(dep[j] < arr[i] || arr[j] > dep[i])) 
                need++;
            }
            ans = max(ans, need);
        }
        return ans;
    }
};

// Greedy
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0, plat = 0, ans = 0;
        
        while(i < n){
            if(arr[i] <= dep[j]){
                plat++;
                ans = max(ans, plat);
                i++;
            } 
            else {
                plat--;
                j++;
            }
        }
        return ans;
    }
};
