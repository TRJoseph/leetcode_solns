# bad only beats 7% of solutions but whatever
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        wordsArr = []

        wordArr = []

        constructingWord = False

        for i in range(0, len(s)):
            if s[i] == " " and not constructingWord:
                continue
                
            if s[i] != " ":
                wordArr.append(s[i])
                constructingWord = True
            else:
                wordsArr.append("".join(wordArr))
                wordArr = []
                constructingWord = False

        if wordArr:
            wordsArr.append("".join(wordArr))
            wordArr = []

        return " ".join(reversed(wordsArr))