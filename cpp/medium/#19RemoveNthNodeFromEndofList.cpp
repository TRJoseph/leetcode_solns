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

        ListNode* rover = head;
        // O(n) traversal
        // while rover->next ! null 
        int listLen = 0;
        while(rover != nullptr) {
            listLen++;
            rover = rover->next;
        }

        // edge cases
        if(listLen <= 1 && n == 1) {
            return nullptr;
        }

        if(listLen == n) {
            return head->next;
        }

        rover = head;
        ListNode* prev = head;

        int currIdx = 0;
        // 3 > 2
        while(listLen - n > currIdx) {
            // previous obviously needs to be incremented down the list one less time
            rover = rover->next;
            if(currIdx > 0) {
                prev = prev->next;
            }
            currIdx++;
        }

        ListNode* next = rover->next;
        prev->next = next;

        return head;
    }
};