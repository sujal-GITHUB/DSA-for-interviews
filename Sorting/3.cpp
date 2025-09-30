// Insertion Sort

// Idea: Insert each element into its correct position in the sorted part.

// Time Complexity: O(n²), but works well for nearly sorted arrays.

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}