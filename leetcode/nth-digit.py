#https://leetcode.com/problems/nth-digit/description/
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findNthDigit(self, n):
        tenth = 0
        number = 0
        if (n < 10):
            return n
        while(n - (9 * (10 ** tenth) * (tenth + 1) ) > 0):
            n = n - (9 * (10 ** tenth) * (tenth + 1) )
            number = number + (10 ** tenth) * 9
            tenth = tenth + 1
        
        mod = n % (tenth + 1)
        n = n - mod
        number = number + n/(tenth + 1)
        if (mod > 0):
            nextNumber = str(number + 1)
            return int(nextNumber[mod - 1])
        return number % 10

s = Solution()
print s.findNthDigit(69)
