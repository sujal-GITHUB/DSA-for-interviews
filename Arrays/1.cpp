// Second Largest

// Link: https://www.geeksforgeeks.org/problems/second-largest3735/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int lar = arr[0];
        int sec = -1;
        
        for(auto a: arr){
            if(a > lar){
                sec = lar;
                lar = a;
            }
            else if(a > sec && a != lar){
                sec = a;
            }
        }
        
        return sec;
    }
};