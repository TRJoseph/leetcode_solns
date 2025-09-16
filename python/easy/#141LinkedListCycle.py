# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        newdict = dict()

        # put listnodes in dict and check if next ptr points to one
        rover = head

        while rover != None:
            if rover in newdict:
                return True

            newdict[rover] = 1

            rover = rover.next

        return False