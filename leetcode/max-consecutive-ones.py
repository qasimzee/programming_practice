# https://leetcode.com/problems/max-consecutive-ones/description/
class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = 0
        maxS = 0
        for x in nums:
            if x == 1:
                s += 1
            else:
                if maxS < s:
                    maxS = s
                s = 0
        if s > 0 and s > maxS:
            maxS = s
        return maxS
