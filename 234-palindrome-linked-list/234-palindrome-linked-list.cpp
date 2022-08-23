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
        ListNode* slow = head, *fast = head;
        int n = 0;
        vector<int> upperHalf;
        
        while(head && head->next) {
            head = head->next->next;
            fast = fast->next;
        }
        
        while(fast) {
            upperHalf.push_back(fast->val);
            fast = fast->next;
        }
        
        reverse(upperHalf.begin(), upperHalf.end());
        
        int idx = 0;
        while(idx < upperHalf.size()) {
            if(slow->val != upperHalf[idx]) return false;
            slow = slow->next;
            idx++;
        }
        
        return true;
    }
};

/*
start ptr, mid ptr
check if they equal

*/