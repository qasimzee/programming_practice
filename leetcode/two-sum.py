# https://github.com/qasimzee/programming_practice/blob/master/leetcode/two-sum.py
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sorted_nums = sorted(nums)
        i = 0
        j = len(sorted_nums) - 1
        while sorted_nums[i] + sorted_nums[j] != target:
            if sorted_nums[i] + sorted_nums[j] > target:
                j -= 1
            elif sorted_nums[i] + sorted_nums[j] < target:
                i += 1
        i = nums.index(sorted_nums[i])
        for x in range(len(nums)):
            if sorted_nums[j] == nums[x] and i != x:
                j = x
                break
        return [i, j]
