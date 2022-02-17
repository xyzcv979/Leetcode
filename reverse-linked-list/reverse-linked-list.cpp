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
            return NULL;
        ListNode *currHead = head;
        while(head->next){
            ListNode *prev = head->next;
            head->next = head->next->next;
            prev->next = currHead;
            currHead = prev;
        }
        return currHead;
    }
};