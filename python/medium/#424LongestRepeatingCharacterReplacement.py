# TODO REVISIT THIS AND STUDY SOLUTION:
class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        counts = dict()
        leftPtr = 0
        maxfreq = 0
        maxlen = 0

        for i in range(len(s)):
            counts[s[i]] = counts.get(s[i], 0) + 1
            maxfreq = max(maxfreq, counts[s[i]])

            while (i - leftPtr + 1) - maxfreq > k:
                counts[s[leftPtr]] -= 1
                leftPtr += 1

            maxlen = max(maxlen, i - leftPtr + 1)

        return maxlen