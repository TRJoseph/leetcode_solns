# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# This solution only beats 5% of runtime, but did it without any assistance very quickly, so of course I left some optimization on the table
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        dummy = ListNode()
        current = dummy

        rover = head

        # count nodes since we arent given nodes
        nodeCount = 0
        while rover != None:
            nodeCount += 1
            rover = rover.next

        rover = head
        
        # get latter half of the list to then create alternating list of elements
        cnt = 0
        latterHalfList = []
        while rover != None:
            if cnt >= nodeCount / 2:
                latterHalfList.append(rover)
            cnt+=1
            rover = rover.next

        rover = head
        cnt = 0
        # create alternating list of elements
        while cnt < nodeCount:
            if cnt % 2 == 0:
                current.next = rover
                rover = rover.next
            else:
                current.next = latterHalfList.pop()

            current = current.next
            cnt += 1

            
        current.next = None