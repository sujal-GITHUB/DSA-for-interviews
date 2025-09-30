// Selection Sort

// Idea: Repeatedly select the minimum element from unsorted part and put it in sorted part.

// Time Complexity: O(n²), fewer swaps than bubble sort.

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIdx]) 
            minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}