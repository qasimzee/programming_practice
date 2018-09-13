# https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        q = []
        if root is None:
            return []
        q.append((root, 0))
        max_dict = {}
        while len(q) > 0:
            node = q[0]
            del q[0]
            max_dict[node[1]] = float('-inf') if not node[1] in max_dict else max_dict[node[1]]
            if node[0].val > max_dict[node[1]]:
                max_dict[node[1]] = node[0].val
            if node[0].left is not None:
                q.append((node[0].left, node[1] + 1))
            if node[0].right is not None:
                q.append((node[0].right, node[1] + 1))
        max_arr = [None] * len(max_dict)
        for key, val in max_dict.items():
            max_arr[key] = val
        return max_arr
