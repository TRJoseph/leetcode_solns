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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr) {
            fast = fast->next;
            
            if(fast == nullptr) {
                slow->next = nullptr;
                break;
            }
            
            if(fast->val != slow->val) {
                slow->next = fast;
                slow = fast;
            }
        }
        return head;
    }
};