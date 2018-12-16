# https://leetcode.com/contest/weekly-contest-97/problems/uncommon-words-from-two-sentences/
class Solution:
    def uncommonFromSentences(self, A, B):
        words_dict = {}
        for x in (A, B):
            for word in x.split():
                if not words_dict.get(word):
                    words_dict[word] = 1
                else:
                    words_dict[word] = words_dict[word] + 1
        return [word for (word, count) in words_dict.items() if count == 1]
