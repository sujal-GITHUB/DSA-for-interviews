// Reverse Linked List

// Link: https://leetcode.com/problems/reverse-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Iterative

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
        return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(head){
            ListNode* nextN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextN;
        }

        return prev;
    }
};

// Recursive

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
        return head;

        ListNode* nHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return nHead;
    }
};