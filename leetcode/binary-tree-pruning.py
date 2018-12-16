# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root.left == None and root.right == None and root.val == 0:
            return None
        if root.left:
            root.left = self.pruneTree(root.left)
        if root.right:
            root.right = self.pruneTree(root.right)
        if root.left == None and root.right == None and root.val == 0:
            return None
        return root
