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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }

        if(head->next == nullptr) {
            return head;
        }
        // list should be at least a pair by now
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        ListNode* newHead = curr;

        while(prev != nullptr) {
            curr->next = prev;
            prev->next = next;
            curr = prev;
            prev = next;
            if(prev != nullptr && prev->next != nullptr) {
                curr->next = next->next;
                curr = next->next;
                next = curr->next;
            } else {
                break;
            }
        }

        return newHead;
    }
};