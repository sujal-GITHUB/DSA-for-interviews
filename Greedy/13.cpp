// Page Faults in LRU

// Link: https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        if(C == 0) 
        return N;
        
        deque<int>dq;
        int cnt = 0;
        
        for(int i=0; i<N; i++){
            auto it = find(dq.begin(), dq.end(), pages[i]);
            
            if(it == dq.end() && dq.size() < C){
                dq.push_back(pages[i]);
                cnt++;
            }
            else if(it == dq.end()){
                dq.pop_front();
                dq.push_back(pages[i]);
                cnt++;
            }
            else{
                dq.erase(it);
                dq.push_back(pages[i]);
            }
        }
        return cnt;
    }
};