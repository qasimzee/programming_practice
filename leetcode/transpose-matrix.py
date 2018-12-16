# https://leetcode.com/problems/transpose-matrix/description/
class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        if not len(A):
            return A
        ret = [list() for i in range(len(A[0]))]
        for i in range(len(A[0])):
            for j in range(len(A)):
                ret[i].append(A[j][i])
        return ret
