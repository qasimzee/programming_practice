#python solution for https://leetcode.com/problems/maximum-binary-tree/description/
class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return TreeNode(nums[0])
        max_index = nums.index(max(nums))
        treeNode = TreeNode(nums[max_index])
        treeNode.left = self.constructMaximumBinaryTree(nums[:max_index])
        treeNode.right = self.constructMaximumBinaryTree(nums[max_index + 1:])
        return treeNode
