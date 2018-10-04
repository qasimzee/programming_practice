# https://leetcode.com/problems/path-sum-iii/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root:
            return 0
        path_count = 0
        que = deque()
        que.append((root, [root.val]))
        while que:
            node = que.popleft()
            path_count += node[1].count(sum)
            if node[0].left:
                new_sum = [i + node[0].left.val for i in node[1]] + [node[0].left.val]
                que.append((node[0].left, new_sum))
            if node[0].right:
                new_sum = [i + node[0].right.val for i in node[1]] + [node[0].right.val]
                que.append((node[0].right, new_sum))
        return path_count
