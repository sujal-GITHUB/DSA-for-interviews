#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int n, int i) {
    int largest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2; 

    if(left < n && arr[left] > arr[largest])
    largest = left;

    if(right < n && arr[right] > arr[largest])
    largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for(int i=n/2-1; i >= 0; i--){
        Heapify(arr, n, i);
    }
}

void HeapSort(int arr[], int n) {
    buildHeap(arr, n);

    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);   // move max to end
        Heapify(arr, i, 0);     // heapify reduced heap
    }
}

int main() {
    int arr[] = {1, 56, 11, 552, 44, 857, 3, 0, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    HeapSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
