#https://leetcode.com/problems/palindromic-substrings/description/
class Solution(object):
    def countSubstrings(self, s):
        i = 0
        count = 0
        while (i < len(s)):
            j = 0
            while (i - j >= 0 and i + j < len(s) and s[i - j] == s[i + j]):
                count = count + 1
                j = j + 1
            j = 0
            while (i - j >= 0 and i + j + 1 < len(s) and s[i - j] == s[i + j + 1]):
                count = count + 1
                j = j + 1
            i = i + 1
        return count

s = Solution()
print s.countSubstrings("abbbcbc")
