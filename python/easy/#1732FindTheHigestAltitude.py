class Solution(object):
    def largestAltitude(self, gain):
        """
        :type gain: List[int]
        :rtype: int
        """
        highestAlt = 0
        runningAlt = 0
        for i in range(0, len(gain)):
            runningAlt += gain[i]
            if(runningAlt > highestAlt):
                highestAlt = runningAlt
        return highestAlt