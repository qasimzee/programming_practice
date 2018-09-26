# https://leetcode.com/problems/shortest-completing-word/description/
class Solution:
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        lp_chars = {}
        for ch in licensePlate:
            if ch.isalpha():
                lp_chars[ch.lower()] = 1 if not ch.lower() in lp_chars else lp_chars[ch.lower()] + 1
        
        ans = ''
        for word in words:
            tmp_lp_chars = {key: val for key, val in lp_chars.items()}
            for ch in word:
                if ch in tmp_lp_chars and tmp_lp_chars[ch] > 0:
                    tmp_lp_chars[ch] = tmp_lp_chars[ch] - 1 
            print(tmp_lp_chars)
            found = True
            for key, val in tmp_lp_chars.items():
                if val > 0:
                    found = False
            if found:
                if ans == '':
                    ans = word
                elif len(ans) > len(word):
                    ans = word
        return ans
