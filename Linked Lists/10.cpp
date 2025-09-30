// Delete the Middle Node of a Linked List

// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        if(head-> next == NULL)
        {
            head = NULL;
            return head;
        }

        while(fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp-> next = slow-> next;
        slow = NULL;
        return head;
    }
};