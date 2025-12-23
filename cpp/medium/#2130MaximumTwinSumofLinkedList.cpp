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
    int pairSum(ListNode* head) {

        // if list is two nodes long just return the sum of the two nodes
        if(head->next->next == nullptr) {
            return head->val + head->next->val;
        }

        // fast pointer slow pointer
        // reverse second half of list
        // create new fast pointer and slow pointer and then count maximum twin sum

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* before = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast != nullptr) {
                before = before->next;
            }
        }
        // slow should be halfway through list
        // prev holds the last node before the halfway split
        // reverse second half of list

        ListNode* curr = slow;
        ListNode* prev = nullptr;

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // re-link list, prev is hopefully on the last node here lol
        before->next = prev;

        fast = prev;
        slow = head;
        int twinSum = 0;

        while(fast != nullptr) {
            twinSum = max(twinSum, fast->val + slow->val);
            slow = slow->next;
            fast = fast->next;
        }

        return twinSum;
    }
};