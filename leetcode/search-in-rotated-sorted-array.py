# https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1
        s = 0
        e = len(nums) - 1
        m = int((s + e) / 2)
        while s <= e:
            if target == nums[m]:
                return m
            if target < nums[m]:
                if nums[s] < nums[m] and target >= nums[s] or target < nums[e] and nums[m] < nums[e]:
                    e = m - 1
                else:
                    s = m + 1
            else:
                if nums[m] < nums[e] and target <= nums[e] or target > nums[s] and nums[s] < nums[m]:
                    s = m + 1
                else:
                    e = m - 1
            m = int((s + e) / 2)
        return -1
