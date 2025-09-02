class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []

        for c in range(0, len(s)):
            if s[c] != "*":
                # append character
                stack.append(s[c])
            else:
                # pop character off stack
                stack.pop()
        
        return "".join(stack)