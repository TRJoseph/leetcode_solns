# bad O(n^2) solution I came up with pretty quickly
class Solution(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        map1 = {i: item for i, item in enumerate(nums1)}
        map2 = {i: item for i, item in enumerate(nums2)}

        ans = [[] for i in range(2)]

        for i in range(0, len(nums1)):
            if map1[i] not in nums2 and map1[i] not in ans[0]:
                ans[0].append(map1[i])
        
        for i in range(0, len(nums2)):
            if map2[i] not in nums1 and map2[i] not in ans[1]:
                ans[1].append(map2[i])

        return ans