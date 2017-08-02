#https://leetcode.com/problems/keyboard-row/
class Solution(object):
    def findWords(self, words):
        keyboard = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        op = []
        for word in words:
            if (word == ""):
                op.append(word)
            else:
                valid = 1
                for line in keyboard:
                    if (word[0].lower() in line):
                        for char in word:
                            if (not char.lower() in line):
                                valid = 0
                if valid == 1:
                    op.append(word)
        return op
