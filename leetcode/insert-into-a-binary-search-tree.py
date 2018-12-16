# https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if root is None:
            root = TreeNode(val)
            return root
        current = root
        while current is not None:
            if val < current.val:
                if current.left is None:
                    current.left = TreeNode(val)
                    break
                current = current.left
            else:
                if current.right is None:
                    current.right = TreeNode(val)
                    break
                current = current.right
        return root
        
