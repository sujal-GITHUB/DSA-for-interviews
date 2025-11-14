// Hand of Straights

// Link: https://leetcode.com/problems/hand-of-straights/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
        return false;

        map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[hand[i]]++;
        }

        while(!mpp.empty()){
            int curr = mpp.begin()->first;

            for(int i=0; i<groupSize; i++){
                if(mpp.find(curr+i) == mpp.end())
                return false;

                mpp[curr+i]--;
                if(mpp[curr+i] == 0)
                mpp.erase(curr+i);
            }
        }
        return true;
    }
};

// Approach 2

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
            return false;

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[hand[i]]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &it: mp){
            pq.push(it.first);
        }

        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();

            if(mp[curr] == 0)
                continue;

            int need = mp[curr];

            for(int i=0; i<groupSize; i++){
                if(mp[curr+i] < need)
                    return false;

                mp[curr+i] -= need;
            }
        }

        return true;
    }
};
