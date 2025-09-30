// Counting Sort (only for integers in limited range)

// Idea: Count occurrences of each number and place them accordingly.

// Time Complexity: O(n + k), where k = range of input.

#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxEl = *max_element(arr.begin(), arr.end());
    vector<int> count(maxEl+1, 0);

    for(int x : arr) 
    count[x]++;
    
    int idx = 0;
    for(int i = 0; i <= maxEl; i++) {
        while(count[i]--) arr[idx++] = i;
    }
}