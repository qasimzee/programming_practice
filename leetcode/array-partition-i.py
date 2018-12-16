# https://leetcode.com/problems/array-partition-i/description/
class Solution:
    def arrayPairSum(self, nums):
        nums.sort()
        s = 0
        for i in range(0,len(nums),2):
            s = s + nums[i]
        return s
