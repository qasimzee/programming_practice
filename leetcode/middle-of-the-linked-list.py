# https://leetcode.com/problems/middle-of-the-linked-list/description/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head):
        first = head
        second = head
        while second and second.next:
            first = first.next
            second = second.next.next
        return first
        
