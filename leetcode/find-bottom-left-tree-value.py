#https://leetcode.com/problems/find-bottom-left-tree-value/description/
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        q = collections.deque()
        q.appendleft([1, root])
        maxleft = [1, root.val]
        while (len(q) > 0):
            pair = q.pop()
            if (pair[1].left is not None):
                if (pair[0] >= maxleft[0]):
                    maxleft = [pair[0] + 1, pair[1].left.val]
                q.appendleft([pair[0] + 1, pair[1].left])
            if (pair[1].right is not None):
                if (pair[0] >= maxleft[0]):
                    maxleft = [pair[0] + 1, pair[1].right.val]
                q.appendleft([pair[0] + 1, pair[1].right])
        return maxleft[1]
