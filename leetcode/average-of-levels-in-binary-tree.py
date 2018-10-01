# https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
from statistics import mean

class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        queue = deque()
        levels = []
        queue.append((root, 0))
        while queue:
            node_tuple = queue.popleft()
            if node_tuple[0]:
                if node_tuple[0].left:
                    queue.append((node_tuple[0].left, node_tuple[1] + 1))
                if node_tuple[0].right:
                    queue.append((node_tuple[0].right, node_tuple[1] + 1))
                if len(levels) > node_tuple[1]:
                    levels[node_tuple[1]].append(node_tuple[0].val)
                else:
                    levels.append([node_tuple[0].val])
        return [mean(level) for level in levels]
        
