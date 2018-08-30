# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
from copy import deepcopy
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    parents = []
    def findAllParents(self, root, n):
        if n.val == root.val:
            self.parents.append(root)
            return True
        if root.left != None:
            ret_value = self.findAllParents(root.left, n)
            if ret_value:
                self.parents.append(root)
                return True
        if root.right != None:
            ret_value = self.findAllParents(root.right, n)
            if ret_value:
                self.parents.append(root)
                return True
        return False
        
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.findAllParents(root, p)
        p_parents = deepcopy(self.parents)
        p_parents.reverse()
        self.parents = []
        self.findAllParents(root, q)
        q_parents = deepcopy(self.parents)
        self.parents = []
        q_parents.reverse()
        common_ancestor = None
        for i in range(min(len(p_parents), len(q_parents))):
            if p_parents[i].val == q_parents[i].val:
                common_ancestor = q_parents[i]
        return common_ancestor
