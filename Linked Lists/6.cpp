// Length of the loop in Linked List

// Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(!head || !head->next)
        return 0;
        
        Node* slow = head;
        Node* fast = head;
        
        bool hasCycle = false;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        
        if(!hasCycle){
            return 0;
        }
        
        int cnt = 1;
        Node* temp = slow->next;
        while(temp != slow){
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
};