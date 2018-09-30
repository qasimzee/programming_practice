# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        traversal_array = []
        stack = []
        stack_parent = []
        if not root:
            return []
        stack.append(root)
        while stack:
            node = stack.pop()
            if node:
                stack.append(node.right)
                stack.append(node.left)
                stack_parent.append(node)
            else:
                if stack_parent:
                    traversal_array.append(stack_parent.pop())
                if stack and stack_parent and stack[-1] == stack_parent[-1].right:
                    traversal_array.append(stack_parent.pop())
                    traversal_array.append(stack.pop())
        return [node.val for node in traversal_array if node is not None]
