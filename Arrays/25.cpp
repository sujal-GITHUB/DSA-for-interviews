// Merge Sorted Array

// Link: https://leetcode.com/problems/merge-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m;
        int i = 0;
      
        while(i < n){
            nums1[j] = nums2[i];
            j++;
            i++;
        }

        sort(nums1.begin(),nums1.end());
    }
};

// Approach 2

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x = m + n - 1;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) 
            nums1[x--] = nums1[i--];

            else 
            nums1[x--] = nums2[j--];
        }

        while (j >= 0) 
        nums1[x--] = nums2[j--];
    }
};
