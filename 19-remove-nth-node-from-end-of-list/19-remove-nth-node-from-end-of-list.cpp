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
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *lastNode = temp;
        ListNode *firstNode = temp;
        for(int i = 0; i <= n; i++){
            lastNode = lastNode->next;
        }
        while(lastNode != NULL){
            lastNode = lastNode->next;
            firstNode = firstNode->next;
        }
        firstNode->next = firstNode->next->next;
        
        return temp->next;
    }
};