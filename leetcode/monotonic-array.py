# https://leetcode.com/problems/monotonic-array/description/
class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        inc_dec_neutral = 0
        for i in range(1, len(A)):
            if A[i] < A[i - 1]:
                if inc_dec_neutral == 1:
                    return False
                inc_dec_neutral = -1
            elif A[i] > A[i - 1]:
                if inc_dec_neutral == -1:
                    return False
                inc_dec_neutral = 1
        return True
