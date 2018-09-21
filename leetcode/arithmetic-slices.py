# https://leetcode.com/problems/arithmetic-slices
class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if len(A) < 3:
            return 0
        start = 0
        ans = 0
        i = 2
        while i < len(A):
            if A[i - 1] - A[i - 2] != A[i] - A[i - 1]:
                count = i - start - 2
                if count > 0:
                    ans += int(count * (count + 1) / 2)
                start = i - 1
            i += 1
        if i - start >= 3:
            count = i - start - 2
            ans += int(count * (count + 1) / 2)
        return ans
