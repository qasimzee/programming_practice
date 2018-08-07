# https://leetcode.com/problems/peak-index-in-a-mountain-array/description 
class Solution(object):
    def peakIndexInMountainArray(self, A):
        max_elem = max(A)
        for i in range(len(A)):
            if A[i] == max_elem:
                return i
            
