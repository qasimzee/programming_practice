# https://leetcode.com/problems/leaf-similar-trees/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findLeaves(self, root, leaves):
        if root.left == None and root.right==None:
            leaves.append(root.val)
            return
        if root.left:
            self.findLeaves(root.left, leaves)
        if root.right:
            self.findLeaves(root.right, leaves)
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        leaves1 = []
        leaves2 = []
        self.findLeaves(root1, leaves1)
        self.findLeaves(root2, leaves2)
        return leaves1 == leaves2
