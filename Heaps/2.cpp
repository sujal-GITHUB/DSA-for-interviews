// Heapify

// Recursive (0-based) -> TC = O(log n)
void maxHeapify_rec(vector<int>& A, int n, int i) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if (l < n && A[l] > A[largest]) largest = l;
    if (r < n && A[r] > A[largest]) largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify_rec(A, n, largest);
    }
}

// Iterative (0-based) -> TC = O(log n)
void maxHeapify_iter(vector<int>& A, int n, int i) {
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;

        if (l < n && A[l] > A[largest]) largest = l;
        if (r < n && A[r] > A[largest]) largest = r;

        if (largest == i) break;

        swap(A[i], A[largest]);
        i = largest;
    }
}

// Build max-heap (0-based) -> TC = O(n)
void buildHeap(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i) {
        // choose either recursive or iterative version:
        maxHeapify_rec(a, n, i);
        // maxHeapify_iter(a, n, i);
    }
}