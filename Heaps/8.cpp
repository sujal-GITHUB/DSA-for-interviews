// Merge k Sorted Lists

// Link: https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>>pq;

        for(int i=0; i<n; i++){
            ListNode* list = lists[i];
            while(list){
                pq.push(list->val);
                list = list->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!pq.empty()){
            ListNode* node = new ListNode(pq.top());
            pq.pop();

            curr->next = node;
            curr = node;
        }

        return dummy->next;
    }
};