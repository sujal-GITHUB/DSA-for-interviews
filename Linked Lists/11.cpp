// Remove Nth Node From End of List

// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        ListNode* slow = head;

        if(fast==NULL)
        return head->next;

        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};