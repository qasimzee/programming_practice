# https://leetcode.com/problems/3sum/description/
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        nums = sorted(nums)
        i = 0
        while i < len(nums):
            x = i + 1
            y = len(nums) - 1
            target = -1 * nums[i]
            while x < y:
                sum = nums[x] + nums[y]
                if sum < target:
                    x += 1
                elif sum > target:
                    y -= 1
                else:
                    triplet = [nums[x], nums[i], nums[y]]
                    ret.append(triplet)
                    while x < y and nums[x] == triplet[0]:
                        x += 1
                    while x < y and nums[y] == triplet[2]:
                        y -= 1
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            i += 1
        return ret
