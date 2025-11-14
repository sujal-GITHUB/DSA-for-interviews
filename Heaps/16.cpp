// Find Median from Data Stream

// Link: https://leetcode.com/problems/find-median-from-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>>minHeap;
    priority_queue<int>maxHeap;

    MedianFinder() {

    }
    
    void addNum(int num) { 
        if(maxHeap.empty() || maxHeap.top() >= num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        //Balance heaps
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }
        else{
            return (double)((maxHeap.top() + minHeap.top())/2.0);
        }
    }
};
