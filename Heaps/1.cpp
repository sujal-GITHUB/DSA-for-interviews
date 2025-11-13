// Heap : A heap is a complete binary tree that follows a specific ordering property:
// n nodes -> Height : log(n)
// Node -> i
// Parent(i) -> floor(i/2)
// Left child -> 2*i
// Right child -> 2*i + 1

// Max Heap
// Every parent node is greater than or equal to its children.
// Root = largest element.

// Min Heap
// Every parent node is less than or equal to its children.
// Root = smallest element.

// Insert

void Insert(int A[], int value, int &n) {
    n = n + 1;          // Increase heap size
    A[n] = value;       // Insert at last index

    int i = n;

    // Fix the max-heap property by shifting up
    while(i > 1){
        int parent = i / 2;

        if(A[parent] < A[i]){
            swap(A[parent], A[i]);
            i = parent;
        } 
        else {
            return;
        }
    }
}

// Delete

int Delete(int A[], int &n) {
    if(n == 0) 
    return -1;     // heap empty

    int deletedValue = A[1];   // root element (max)

    A[1] = A[n];               // move last element to root
    n = n - 1;                 // reduce heap size

    int i = 1;

    // Heapify downward (shift down)
    while (true) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        // find larger child
        if (left <= n && A[left] > A[largest])
            largest = left;

        if (right <= n && A[right] > A[largest])
            largest = right;

        // If parent is smaller → swap
        if (largest != i) {
            swap(A[i], A[largest]);
            i = largest;       // move down
        } 
        else {
            break;
        }
    }

    return deletedValue;
}
