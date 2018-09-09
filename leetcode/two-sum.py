# https://github.com/qasimzee/programming_practice/blob/master/leetcode/two-sum.py
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        tmp_nums = [num for num in nums]
        nums.sort()
        ptr1 = 0
        ptr2 = len(nums) - 1
        while nums[ptr1] + nums[ptr2] != target:
            if nums[ptr1] + nums[ptr2] > target:
                ptr2 -= 1
            elif nums[ptr1] + nums[ptr2] < target:
                ptr1 += 1
        first_num = -1
        second_num = -1
        for i in range(len(tmp_nums)):
            if first_num == -1 and nums[ptr1] == tmp_nums[i]:
                first_num = i
            elif second_num == -1 and nums[ptr2] == tmp_nums[i]:
                second_num = i
        return [first_num, second_num]
