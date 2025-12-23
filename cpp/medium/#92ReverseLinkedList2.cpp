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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // nothing to reverse
        if(head->next == nullptr || left == right) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* behind = head;
        int position = 1;
        
        while(curr != nullptr && position < left) {
            // skips first iteration so its lagging behind by 1 
            if(curr != head) {
                behind = behind->next;
            }
            curr = curr->next;
            position++;
        }
        
        // now curr and behind will be at optimal position and we need to reverse the list
        ListNode* prev = nullptr;
        ListNode* after = nullptr;
        int reversePos = position;
        
        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            if(reversePos == right) {
                // get placeholder pointer before reversing
                after = curr;
                break;
            }
            reversePos++;
        }
        
        // if this is true, we were not reversing from the first node so we have to relink
        if(position > 1) {
            behind->next->next = after;
            behind->next = prev;
        } else {
            behind->next = after;
            return prev;
        }
        return head;
        
    }
};