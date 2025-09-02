class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        maxAvg = 0
        runningAvg = 0

        # do the first k values
        for i in range(0, k):
            maxAvg += nums[i]

        runningAvg = maxAvg

        for i in range(0, len(nums)-k):
            runningAvg -= nums[i]
            runningAvg += nums[i+k]
            if runningAvg > maxAvg:
                maxAvg = runningAvg

        output = float(maxAvg) / k
        return output