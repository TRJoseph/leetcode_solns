# this is the naive solution im assuming, I was able to get this fairly quickly,
# runs out of time on leetcode submission
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        mArea = 0
        rightPtr = len(height) - 1

        for leftPtr in range(0, len(height)):
            
            while(rightPtr >= leftPtr):
                currArea = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr])
                mArea = max(mArea, currArea)
                rightPtr-= 1
            
            rightPtr = len(height) - 1

        return mArea
    
# this is a little better, beats 35% now (still eh but 0 outside assistance done in like two minutes)

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        mArea = 0
        arr_len = len(height)
        rightPtr = arr_len - 1
        leftPtr = 0
        dist = arr_len -1

        while (leftPtr <= rightPtr):
            currArea = dist * min(height[leftPtr], height[rightPtr])
            mArea = max(mArea, currArea)

            if(height[leftPtr] < height[rightPtr]):
                leftPtr +=1
            else:
                rightPtr-= 1

            dist-=1
       
            

        return mArea