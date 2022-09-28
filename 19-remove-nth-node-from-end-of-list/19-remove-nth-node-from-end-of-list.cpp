/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head, *right = head, *prev = NULL;
        
        // 1. loop right ptr to n
        for(int i = 0; i < n; i++) {
            right = right->next;
        }
        
                
        // left did not move.
        // [1] n = 1. Should output []
        if(!right) {
            return left->next;
        }
        
        // 2. loop right and left till right hits end
        while(right) {
            right = right->next;
            prev = left;
            left = left->next;
        }

        // Set prev->next to left->next
        prev->next = left->next;
        left->next = NULL;
        
        return head;
    }
};

/*
loop till n, right ptr
loop till end, right ptr, left ptr
left ptr = on nth node
need to track previous of left

prev->next = nth node ->next
nth node->next = null
*/