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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> hashSet;
        while(headA != NULL){
            hashSet.insert(headA);
            headA = headA->next;
        }
        while(headB != NULL){
            if(hashSet.find(headB) != hashSet.end()){
                return headB;
            }
            headB = headB->next;
        }
        
        return NULL;
    
    }
};