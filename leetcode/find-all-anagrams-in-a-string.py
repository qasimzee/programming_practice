# https://leetcode.com/problems/find-all-anagrams-in-a-string
class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        anagram_index = []
        if len(p) > len(s):
            return []
        p_dict = [0]*26
        s_dict = [0]*26
        for ch in p:
            p_dict[ord(ch) - 97] = p_dict[ord(ch)- 97] + 1
        for i in range(len(s) - len(p) + 1):
            if i == 0:
                for ch in s[0:len(p)]:
                    s_dict[ord(ch)- 97] = s_dict[ord(ch)- 97] + 1
            else:
                s_dict[ord(s[i-1])- 97] = s_dict[ord(s[i-1])- 97] - 1
                index = ord(s[i + len(p) - 1])- 97
                s_dict[index] = s_dict[index] + 1
            if s_dict == p_dict:
                anagram_index.append(i)
        return anagram_index
