// Radix Sort (for integers)

// Idea: Sort numbers digit by digit using counting sort as a subroutine.

// Time Complexity: O(d*(n + k)), where d = number of digits.

#include<bits/stdc++.h>
using namespace std;

void countingSortDigit(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n), count(10, 0);

    for(int x : arr) 
    count[(x/exp)%10]++;

    for(int i = 1; i < 10; i++) 
    count[i] += count[i-1];
    
    for(int i = n-1; i >= 0; i--) {
        int digit = (arr[i]/exp)%10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }
    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxEl = *max_element(arr.begin(), arr.end());
    for(int exp = 1; maxEl/exp > 0; exp *= 10)
        countingSortDigit(arr, exp);
}