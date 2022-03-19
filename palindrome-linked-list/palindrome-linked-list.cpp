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
    bool isPalindrome(ListNode* head) {
        // Reverse, check with original head
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow != NULL){
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* nextHead = NULL;
        while(head != NULL){
            nextHead = head->next;
            head->next = prev;
            prev = head;
            head = nextHead;
        }
        return prev;
    }
};