// Permutation Sequence

// Link: https://leetcode.com/problems/permutation-sequence/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

// TC: O(n! * n + n! log n)
// SC = O(n! * n)

string getPermutation(int n, int k){
    vector<int>nums;
    for(int i=1; i<=n; i++) 
    nums.push_back(i);

    vector<string>all;
    do{
        string s = "";

        for(int x: nums) 
        s += to_string(x);

        all.push_back(s);
    } while (next_permutation(nums.begin(), nums.end()));

    sort(all.begin(), all.end());
    return all[k-1];
}

// Approach 2

// TC : O(k * n)
// SC : O(n)

string getPermutation(int n, int k) {
    vector<int>nums;
    for(int i=1; i<=n; i++) 
    nums.push_back(i);

    for(int i=1; i<k; i++){
        next_permutation(nums.begin(), nums.end());
    }

    string ans = "";
    for(int x: nums) 
    ans += to_string(x);
    return ans;
}

// Approach 3

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>numbers;
        for(int i=1; i<n; i++){
            fact = fact*i;
            numbers.push_back(i);
        }

        numbers.push_back(n);
        string ans = "";
        k--;

        while(true){
            ans += to_string(numbers[k/ fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size() == 0)
            break;

            k %= fact;
            fact /= numbers.size();
        }
        return ans;
    }
};