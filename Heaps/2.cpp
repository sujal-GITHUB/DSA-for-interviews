// Heapify Algorithm -> TC : O(logn)

// Recurisve

void maxHeapify1(int A[], int n, int i) {
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i;

    if(l <= n && A[l] > A[largest]) 
    largest = l;

    if(r <= n && A[r] > A[largest]) 
    largest = r;

    if(largest != i){
        swap(A[i], A[largest]);
        maxHeapify1(A, n, largest);
    }
}


// Iterative

void maxHeapify1_iter(int A[], int n, int i) {
    while (true) {
        int l = 2*i;
        int r = 2*i + 1;
        int largest = i;

        if(l <= n && A[l] > A[largest]) 
        largest = l;

        if(r <= n && A[r] > A[largest]) 
        largest = r;

        if(largest == i) 
        break;

        swap(A[i], A[largest]);

        i = largest;
    }
}

// Build Heap -> TC: O(n)

void buildHeap(vector<int>a, int n){
    for(int i=n/2; i>0; i--){
        heapify(a, n, i);
    }
}