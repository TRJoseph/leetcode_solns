//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* rover;
        ListNode* previous;
        rover = head;

        // node count will always be at least 1
        int n = 1;
        while(rover->next != nullptr) {
            n++;
            rover = rover->next;
        }

        if (n == 1) {
            return nullptr;
        }

        rover = head;
        previous = head;

        for (int i = 1; i <= (n / 2); i ++) {
            previous = rover;
            rover = rover->next;
        }

        if (rover->next != nullptr) {
            previous->next = rover->next;
        } else {
            previous->next = nullptr;
        }

        return head;
        
    }
};