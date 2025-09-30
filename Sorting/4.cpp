//Merge Sort

// Idea: Divide and Conquer – Split array into halves, sort each recursively, then merge.

// Time Complexity: O(n log n), stable sort.

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) 
    L[i] = arr[l+i];

    for(int j = 0; j < n2; j++) 
    R[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) 
        arr[k++] = L[i++];

        else 
        arr[k++] = R[j++];
    }

    while(i < n1) 
    arr[k++] = L[i++];

    while(j < n2) 
    arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}