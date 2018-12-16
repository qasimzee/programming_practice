# https://leetcode.com/problems/single-element-in-a-sorted-array/description/
class Solution:
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start = 0
        end = len(nums) - 1
        middle = math.floor((start + end)/2)
        while end - start > 2:
            if nums[middle] != nums[middle + 1] and nums[middle] != nums[middle - 1]:
                return nums[middle]
            if middle % 2 == 1:
                if nums[middle - 1] != nums[middle]:
                    end = middle
                    if end + 1 < len(nums) and nums[end + 1] == nums[end]:
                        end += 1
                else:
                    start = middle
                    if start > 0 and nums[start - 1] == nums[start]:
                        start -= 1
            else:
                if middle + 1 < len(nums) and nums[middle + 1] != nums[middle]:
                    end = middle
                    if end + 1 < len(nums) and nums[end + 1] == nums[end]:
                        end += 1
                else:
                    start = middle
                    if start > 0 and nums[start - 1] == nums[start]:
                        start -= 1
            middle = math.floor((start + end) / 2)
            print(nums[start: end + 1])
        if nums[start] == nums[start + 1]:
            return nums[end]
        if nums[end] == nums[end - 1]:
            return nums[start]
        return -1
