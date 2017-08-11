#https://leetcode.com/problems/merge-two-binary-trees/description/
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution(object):
    def mergeTrees(self, t1, t2):
        mergedTree = None
        q = deque()
        triplet = []
        if (t1 is not None and t2 is not None):
            mergedTree = TreeNode(t1.val + t2.val)
            triplet = [mergedTree, t1, t2]
        elif (t1 is not None and t2 is None):
            mergedTree = TreeNode(t1.val)
            triplet = [mergedTree, t1, None]
        elif (t1 is None and t2 is not None):
            mergedTree = TreeNode(t2.val)
            triplet = [mergedTree, None, t2]
        if (len(triplet) > 0):
            q.appendleft(triplet)
        while (len(q) > 0):
            triplet = q.pop()
            newTriplet = []
            if (triplet[1] is not None and triplet[2] is not None and triplet[1].left is not None and triplet[2].left is not None):
                triplet[0].left = TreeNode(triplet[1].left.val + triplet[2].left.val)
                newTriplet = [triplet[0].left, triplet[1].left, triplet[2].left]
            elif ((triplet[1] is None or triplet[1].left is None) and (triplet[2] is not None and triplet[2].left is not None)):
                triplet[0].left = TreeNode(triplet[2].left.val)
                newTriplet = [triplet[0].left, None, triplet[2].left]
            elif ((triplet[1] is not None and triplet[1].left is not None) and (triplet[2] is None or triplet[2].left is None)):
                triplet[0].left = TreeNode(triplet[1].left.val)
                newTriplet = [triplet[0].left, triplet[1].left, None]
            if (len(newTriplet) > 0):
                q.appendleft(newTriplet);
            if (triplet[1] is not None and triplet[2] is not None and triplet[1].right is not None and triplet[2].right is not None):
                triplet[0].right = TreeNode(triplet[1].right.val + triplet[2].right.val)
                newTriplet = [triplet[0].right, triplet[1].right, triplet[2].right]
            elif ((triplet[1] is None or triplet[1].right is None) and (triplet[2] is not None and triplet[2].right is not None)):
                triplet[0].right = TreeNode(triplet[2].right.val)
                newTriplet = [triplet[0].right, None, triplet[2].right]
            elif ((triplet[1] is not None and triplet[1].right is not None) and (triplet[2] is None or triplet[2].right is None)):
                triplet[0].right = TreeNode(triplet[1].right.val)
                newTriplet = [triplet[0].right, triplet[1].right, None]
            if (len(newTriplet) > 0):
                q.appendleft(newTriplet);
        return mergedTree


