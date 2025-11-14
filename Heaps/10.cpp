// Task Scheduler

// Link: https://leetcode.com/problems/task-scheduler/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>chars(26, 0);
        for(auto c: tasks){
            chars[c-'A']++;
        }

        int time = 0;
        priority_queue<int>pq;
        
        for(int i=0; i<26; i++){
            if(chars[i] > 0)
            pq.push(chars[i]);
        }

        while(!pq.empty()){
            vector<int>temp;
            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int fr = pq.top();
                    pq.pop();
                    fr--;
                    temp.push_back(fr);
                }
            }

            for(auto c: temp){
                if(c > 0)
                pq.push(c);
            }
            
            if(pq.empty()){
                time += temp.size();
            }
            else{
                time += n+1;
            }
        }
        return time;
    }
};

// Approach 2

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>chars(26, 0);
        int maxFreq = -1;
        for(auto c: tasks){
            chars[c-'A']++;

            if(chars[c-'A'] > maxFreq){
                maxFreq = chars[c-'A'];
            }
        }

        int cnt = 0;
        for(auto c: chars){
            if(c == maxFreq)
            cnt++;
        }

        int time = (maxFreq-1)*(n+1) + cnt;
        int k = tasks.size();
        return max(time, k);
    }
};