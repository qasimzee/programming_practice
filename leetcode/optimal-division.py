# https://leetcode.com/problems/optimal-division/description/
class Solution:
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if len(nums) <= 2:
            return '/'.join([str(i) for i in nums])
        return '{}/({})'.format(nums[0], '/'.join([str(i) for i in nums[1:]]))
