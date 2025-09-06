class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        seenSet = set()

        for i in range(0, len(nums)):
            if nums[i] in seenSet:
                return True
            else:
                seenSet.add(nums[i])

        return False