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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* prev = head;
        while(head->next != NULL){
            ListNode *curr = head->next;
            head->next = head->next->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
};
