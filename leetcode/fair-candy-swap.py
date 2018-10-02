# https://leetcode.com/problems/fair-candy-swap/description/
class Solution:
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        A = sorted(A)
        B = sorted(B)
        i = 0
        j = 0
        sumA = sum(A)
        sumB = sum(B)
        while sumA - A[i] + B[j] != sumB + A[i] - B[j]:
            if sumA - A[i] + B[j] < sumB + A[i] - B[j]:
                j += 1
            elif sumA - A[i] + B[j] > sumB + A[i] - B[j]:
                i += 1
        return [A[i], B[j]]
