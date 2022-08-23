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
    ListNode* frontPtr;
    bool isPalindrome(ListNode* head) {
        frontPtr = head;
        return recurse(frontPtr);
    }
    
    bool recurse(ListNode* currNode) {
        if(!currNode) return true;
        
        if(!recurse(currNode->next)) return false;
        if(currNode->val != frontPtr->val) return false;
        frontPtr = frontPtr->next;
        
        return true;
    }
};

/*
start ptr, mid ptr
check if they equal

*/