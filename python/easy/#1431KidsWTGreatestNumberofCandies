class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """

        # that any single kid has
        greatestNumofCandies = max(candies)

        result = []

        for i in range(0, len(candies)):
            if candies[i] + extraCandies >= greatestNumofCandies:
                result.append(True)
            else:
                result.append(False)
        return result