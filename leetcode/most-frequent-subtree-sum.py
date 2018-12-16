# https://leetcode.com/problems/most-frequent-subtree-sum/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    dict_sum = {}
    def findSubTreeSum(self, root):
        sum = 0
        if root == None:
            return 0
        if root.left:
            sum += self.findSubTreeSum(root.left)
        if root.right:
            sum += self.findSubTreeSum(root.right)
        sum += root.val
        self.dict_sum[sum] = self.dict_sum[sum] + 1 if sum in self.dict_sum else 1
        return sum
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.dict_sum = {}
        self.findSubTreeSum(root)
        if not self.dict_sum:
            return []
        max_val = max(self.dict_sum.values())
        return [key for key, val in self.dict_sum.items() if val == max_val]
