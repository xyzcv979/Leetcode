/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Floyd's tortoise and hare
        // 1. Check if cycle is present
        // 2. Init 2 more ptrs
        //     1 at head, 1 at intersection
        //     advance ptrs till they meet, this is start of cycle
        ListNode *fast = head;
        ListNode *slow = head;
        bool isCycle = false;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                isCycle = true;
                break;
            }
        }
        if(isCycle){
            ListNode *startPtr = head;
            ListNode *cyclePtr = fast;
            while(startPtr != cyclePtr){
                cyclePtr = cyclePtr->next;
                startPtr = startPtr->next;
            }
            return startPtr;
        }
        
        return NULL;
    }
};