# https://leetcode.com/problems/sum-of-square-numbers/description/
class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        i = 0
        while math.sqrt(c - (i * i)) - int(math.sqrt(c - (i * i))) > 0.0:
            i += 1
            if i * i + (c - (i * i)) > c or c - (i * i) < 0:
                return False
        return True
