# https://leetcode.com/problems/self-dividing-numbers/description/
class Solution:
    def isSelfDividing(self, number):
        n = number
        while n > 0:
            d = n % 10
            if d == 0 or number % d != 0:
                return False
            n = int(n/10)
        return True
    def selfDividingNumbers(self, left, right):
        l = []
        for i in range(left, right+1):
            if self.isSelfDividing(i):
                l.append(i)
        return l
