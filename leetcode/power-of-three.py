#https://leetcode.com/problems/power-of-three/description/
class Solution(object):
    def isPowerOfThree(self, n):
        return n > 0 and pow(3, 20) % n == 0
