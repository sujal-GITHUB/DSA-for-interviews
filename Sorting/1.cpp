// Bubble Sort

// Idea: Repeatedly swap adjacent elements if they are in the wrong order.

// Time Complexity: O(n²), good for small arrays.

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break; // already sorted
    }
}