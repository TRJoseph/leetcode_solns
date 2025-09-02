class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ['a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

        reversedString = []

        for i in range(0, len(s)):
            if s[i] in vowels:
                reversedString.append(s[i])

        r = []

        for i in range(0, len(s)):
            if s[i] in vowels:
                r.append(reversedString.pop())
            else:
                r.append(s[i])

        return "".join(r)

