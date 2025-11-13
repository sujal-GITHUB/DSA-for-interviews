#include<bits/stdc++.h>
using namespace std;

// Heap Sort

void Heapify(int arr[], int n, int i){
    int lar = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[left] > arr[lar])
    lar = left;

    if(right<=n && arr[right] > arr[lar])
    lar = right;

    if(lar != i){
        swap(arr[lar], arr[i]);
        Heapify(arr, n, lar);
    }
}

void buildHeap(int arr[], int n){
    for(int i=n/2; i>0; i--){
        Heapify(arr, n, i);
    }
}

void HeapSort(int arr[], int n){
    buildHeap(arr, n);

    for(int i=n; i>1; i--){
        swap(arr[i], arr[1]);
        Heapify(arr, i-1, 1);
    }
}

int main(){
    int arr[] = {1,56,11,552,44,857,3,0,45};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int>a(n + 1);
    for(int i = 0; i < n; ++i) 
    a[i+1] = arr[i];

    HeapSort(a.data(), n);
    
    for(int i = 1; i <= n; ++i) 
    cout<<a[i]<<" ";

    cout<<endl;

    return 0;
}