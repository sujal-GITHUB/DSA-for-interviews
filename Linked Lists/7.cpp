// Palindrome Linked List

// Link: https://leetcode.com/problems/palindrome-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
        return head;

        ListNode* nHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return nHead;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        return true;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* newN = reverse(slow);
        
        ListNode* firstHalf = head;
        ListNode* check = newN;
        while(check){
            if(firstHalf->val != check->val)
                return false;
                
            firstHalf = firstHalf->next;
            check = check->next;
        }

        return true;
    }
};