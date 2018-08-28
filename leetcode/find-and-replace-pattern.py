# https://leetcode.com/problems/find-and-replace-pattern/description/
class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        ret_list = []
        
        
        for word in words:
            tmp_word = list(word)
            pattern_dict = {}
            
            for i in range(len(pattern)):
                if word[i] in pattern_dict:
                    tmp_word[i] = pattern_dict[word[i]]
                elif not pattern[i] in pattern_dict.values():
                    pattern_dict[word[i]] = pattern[i]
                    tmp_word[i] = pattern[i]
            if "".join(tmp_word) == pattern:
                ret_list.append(word)
        return ret_list
