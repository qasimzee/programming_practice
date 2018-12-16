# https://leetcode.com/problems/rotate-string/description/
class Solution:
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        A = list(A)
        B = list(B)
        if len(A) == len(B) and len(A) == 0:
            return True
        if len(A) != len(B):
            return False
        for i in range(len(A)):
            if A == B:
                return True
            x = A.pop()
            A = [x] + A
        return False
