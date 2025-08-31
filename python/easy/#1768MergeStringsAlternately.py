# fast less clean submission
class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        
        w1len = len(word1)
        w2len = len(word2)

        r = ""
        idx = 0

        while(True):

            if idx < w1len:
                r += word1[idx]
            
            if idx < w2len:
                r += word2[idx]

            idx+=1
            if idx >= max(w1len, w2len):
                break

        return r
    
# second slower but cleaner submission, both O(n)
class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        
        w1len = len(word1)
        w2len = len(word2)
        wArr = []

        for i in range(0, max(w1len, w2len)):
            if i < w1len:
                wArr.append(word1[i])
            
            if i < w2len:
                wArr.append(word2[i])


        return "".join(wArr)