// Convert Min Heap to Max Heap

// Link: http://geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1

#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>&arr, int n, int i){
    int lar = i; 
    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l < n && arr[l] > arr[lar]){
        lar = l;
    }
    
    if(r < n && arr[r] > arr[lar]){
        lar = r;
    }
    
    if(lar != i){
        swap(arr[lar], arr[i]);
        maxHeapify(arr, n, lar);
    }
}

void buildHeap(vector<int>&arr, int n){
    for(int i=n/2-1; i>=0; i--){
        maxHeapify(arr, n, i);
    }
}

class Solution {
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        return buildHeap(arr, N);
    }
};
