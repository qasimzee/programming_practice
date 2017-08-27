class Solution(object):
    def checkPossibility(self, nums):
        count = 0
        index = -1
        for i in range (1, len(nums) ):
            if (nums[i] < nums[i - 1]):
                index = i
        
        if (index == -1):
            return True
        back_nums = list(nums)
        back_nums[index-1] = back_nums[index]
        
        flag = False
        for i in range (len(nums) - 1):
            if (back_nums[i] > back_nums[i + 1]):
                flag = True
        if (not flag):
            return True
        flag = False
        nums[index] = nums[index - 1]
        
        for i in range (len(nums) - 1):
            if (nums[i] > nums[i + 1]):
                flag = True
        if (not flag):
            return True
        return False
