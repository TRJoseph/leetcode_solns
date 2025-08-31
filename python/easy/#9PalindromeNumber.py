# first submission, naive approach
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """

        # negative, cannot be a palindrome
        if(x < 0):
            return False

        # all single digit numbers are palindromes
        if (x < 10):
            return True

        s = str(x)

        middleIndex = int(len(s) / 2)

        for i in range(0, middleIndex):
            if s[i] != s[len(s) - 1 - i]:
                return False
            

        return True
    
# second approach, without string conversion, slightly slower it seems
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # negative, cannot be a palindrome
        if(x < 0):
            return False

        reversedNum = 0
        savedx = x

        while x > 0:
            d = x % 10
            reversedNum = reversedNum * 10 + d
            x //= 10

        if reversedNum != savedx:
            return False

        return True