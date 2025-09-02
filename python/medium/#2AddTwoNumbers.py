# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        carry = 0

        output = ListNode()
        outRover = output

        while l1 or l2 or carry:
            tempSum = 0

            if l1:
                tempSum += l1.val

            if l2:
                tempSum += l2.val

            tempSum += carry

            if(tempSum > 9):
                carry = 1
            else:
                carry = 0

            outRover.val = tempSum % 10

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next    

            if l1 or l2 or carry:
                outRover.next = ListNode()
                outRover = outRover.next
                
        return output
