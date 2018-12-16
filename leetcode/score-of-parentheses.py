# https://leetcode.com/problems/score-of-parentheses/description/
class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        stack = []
        for ch in S:
            if ch == '(':
                stack.append(ch)
            if ch == ')':
                current_score = 0
                while len(stack) > 0 and isinstance(stack[-1], int):
                    current_score += stack[-1]
                    stack.pop()
                if stack[-1] == '(':
                    if current_score > 0:
                        current_score *= 2
                    else:
                        current_score = 1
                    stack.pop()
                    stack.append(current_score)
        
        return sum(stack[0:len(stack)]) 
