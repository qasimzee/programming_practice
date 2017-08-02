#https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
class Solution(object):
    def reverseWords(self, s):
        words = s.split();
        return " ".join([word[::-1] for word in words])
