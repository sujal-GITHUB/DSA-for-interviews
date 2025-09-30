// Odd Even Linked List

// Link: https://leetcode.com/problems/odd-even-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* oddI = odd;
        ListNode* even = new ListNode(-1);
        ListNode* eveI = even;

        int cnt = 1;
        while(head){
            if(cnt&1){
                oddI->next = head;
                oddI = oddI->next;
            }
            else{
                eveI->next = head;
                eveI = eveI->next;
            }
            cnt++;
            head = head->next;
        }

        eveI->next = nullptr;
        oddI->next = even->next;
        return odd->next;
    }
};