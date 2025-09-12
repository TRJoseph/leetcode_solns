class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        charmap = {')': '(', ']': '[', '}': '{'}

        stack = []

        for i in range(len(s)):
            if s[i] in charmap:
                if stack and stack[-1] == charmap[s[i]]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(s[i])

        return (not stack)
