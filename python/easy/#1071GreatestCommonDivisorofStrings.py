# beats 100% woohoo!
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """

        len1 = len(str1)
        len2 = len(str2)

        for i in range(min(len1, len2), 0, -1):
            if(len1 % i != 0 or len2 % i != 0):
                continue

            factor1 = len1 // i
            factor2 = len2 // i

            if(str1[:i] * factor1 == str1 and str1[:i] * factor2 == str2):
                return str1[:i]

        return ""