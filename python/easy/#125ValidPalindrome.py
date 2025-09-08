class Solution:
    def isPalindrome(self, s: str) -> bool:

            s = s.lower()

            startptr = 0
            endptr = len(s)-1

            while(startptr <= endptr):
                if(not s[startptr].isalnum()):
                    startptr+=1
                    continue
                if(not s[endptr].isalnum()):
                    endptr-=1
                    continue
                if s[startptr] != s[endptr]:
                    return False
                startptr+=1
                endptr-=1

            return True
