# https://leetcode.com/problems/flipping-an-image/description/
class Solution(object):
    def flipAndInvertImage(self, A):
        for i in range(len(A)):
            A[i].reverse()
        for i in range(len(A)):
            for j in range(len(A[i])):
                A[i][j] = 0 if A[i][j] == 1 else 1
        return A
