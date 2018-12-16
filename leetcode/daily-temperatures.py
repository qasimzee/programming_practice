# https://leetcode.com/problems/daily-temperatures/description/
class Solution:
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        i = len(temperatures) - 1
        res = [0] * len(temperatures)
        while i >= 0:
            j = i + 1
            while j < len(temperatures):
                if temperatures[j] > temperatures[i]:
                    break
                if res[j] > 0:
                    j += res[j]
                else:
                    j = len(temperatures)
            if j < len(temperatures) and temperatures[j] > temperatures[i]:
                res[i] = j - i
            i -= 1
        return res
