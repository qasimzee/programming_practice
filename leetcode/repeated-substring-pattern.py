#https://leetcode.com/problems/repeated-substring-pattern/description/
class Solution(object):
    def repeatedSubstringPattern(self, s):
        for i in range(1, len(s)/2 + 1):
            subStr = s[0:i]
            matched = True
            for j in range(i, len(s), i):
                subStrNext = s[j : j+i]
                
                if (subStr != subStrNext):
                    matched = False
            if (matched):
                return matched
        return False
s = Solution()
print s.repeatedSubstringPattern("ababa")
