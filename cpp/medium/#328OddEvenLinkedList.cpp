// Definition for singly-linked list.
struct ListNode {
   int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = head->next;

        while(even && even->next) {
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }

        odd->next = evenHead;

        return head;
    }
};