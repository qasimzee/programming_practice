#https://leetcode.com/problems/valid-perfect-square/description/
class Solution(object):
    def isPerfectSquare(self, num):
        i = 1
        while (i * i <= num):
            if (i*i == num):
                return True
            i = i + 1
        return False
