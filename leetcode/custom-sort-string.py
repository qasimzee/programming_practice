# https://leetcode.com/problems/custom-sort-string/description/
from collections import Counter
class Solution:
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        res = []
        count = Counter(T)
        for ch in S:
            res.append(count[ch] * ch)
            del count[ch]
        for ch, val in count.items():
            res.append(val * ch)
        return "".join(res)
