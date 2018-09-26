# https://leetcode.com/problems/sort-characters-by-frequency/description/
import operator
class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        count_map = {}
        for ch in s:
            count_map[ch] = count_map[ch] + 1 if ch in count_map else 1
        count_map = sorted(count_map.items(), key = operator.itemgetter(1))
        count_map.reverse()
        ans = ''
        
        for ch, count in count_map:
            ans += ch * count
        return ans
