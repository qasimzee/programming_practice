#https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
class Solution(object):
    def findDuplicates(self, nums):
        res = []
        for x in nums:
            if (nums[abs(x) - 1] < 0):
                res.append(abs(x))
            else:
                nums[abs(x) - 1] *= -1
        return res
