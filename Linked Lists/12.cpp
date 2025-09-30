// Sort List

// Link: https://leetcode.com/problems/sort-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return head;

        vector<int>a;
        // ListNode* ans = new Node(-1)

        ListNode* temp = head;
        while(temp!=NULL){
            a.push_back(temp->val);
            temp = temp->next;
        }

        sort(a.begin(),a.end());
        temp = head;

        for(int i=0;i<a.size();i++){
            ListNode* newN = new ListNode(a[i]);
            head->next = newN;
            head = newN;
        }

        temp=temp->next;
        return temp;
    }
};

// Merge Sort

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        int n = 0;
        ListNode* curr = head;
        while (curr) { n++; curr = curr->next; }
        
        ListNode dummy(0, head);
        ListNode* left;
        ListNode* right;
        ListNode* tail;
        
        for (int step = 1; step < n; step <<= 1) {
            ListNode* prev = &dummy;
            curr = dummy.next;
            while (curr) {
                left = curr;
                right = split(left, step);
                curr = split(right, step);
                prev->next = merge(left, right);
                while (prev->next) prev = prev->next;
            }
        }
        return dummy.next;
    }

    ListNode* split(ListNode* head, int step) {
        if (!head) return nullptr;
        for (int i = 1; head->next && i < step; i++) {
            head = head->next;
        }
        ListNode* next = head->next;
        head->next = nullptr;
        return next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }
};
