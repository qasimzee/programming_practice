# https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
class Solution:
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        result_list=[]
        s=list(s)
        for word in d:
            d_list = list(word)
            j=0
            for i in range(len(s)):
                if j < len(d_list):
                    if d_list[j] == s[i]:
                        j=j+1
                else:
                    break
            if j >= len(d_list):
                result_list.append(word)
        
        result_list.append("")
        result_list.sort()
        result_list.sort(key=len, reverse=True)
        return result_list[0]
