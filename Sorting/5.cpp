// Quick Sort

// Idea: Pick a pivot, partition elements into two halves, recursively sort each.

// Time Complexity: O(n log n) average, O(n²) worst case.

#include<bits/stdc++.h>
using namespace std;

int p(vector<int>& arr, int l, int r){
    int pivot = arr[r];
    int i = l;
    int j = r - 1;

    while(i <= j){
        while(i <= j && arr[i] <= pivot) 
        i++;

        while(i <= j && arr[j] >= pivot) 
        j--;

        if(i < j) 
        swap(arr[i], arr[j]);
    }

    swap(arr[i], arr[r]);
    return i;
}

void quick(vector<int>& arr, int l, int r){
    if(l >= r) 
    return;

    int pi = p(arr, l, r);
    quick(arr, l, pi-1);
    quick(arr, pi+1, r);
}