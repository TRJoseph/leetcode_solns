# bad O(n^2) solution I came up with in like two seconds
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        for i in range(len(nums)-1, -1, -1):
            if(nums[i] == 0):
                # traverse back through the list moving the 0 to the end swapping as it goes
                for j in range(i, len(nums)-1):
                    nums[j] = nums[j+1]
                    nums[j+1] = 0

        return nums
    
# better with actually two pointers
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        # writing pointer
        writeIndex = 0

        for i in range(0, len(nums)):
            if nums[i] != 0:
                nums[writeIndex] = nums[i]
                writeIndex += 1

        for i in range(writeIndex, len(nums)):
            nums[i] = 0

        return nums