# https://leetcode.com/problems/partition-labels/description/
class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        first_index = current_index = last_index = 0
        parts = []
        while current_index < len(S):
            modified = False
            for i in range(last_index + 1, len(S)):
                if S[current_index] == S[i]:
                    last_index = i
            if current_index == last_index:
                parts.append(len(S[first_index:last_index + 1]))
                first_index = current_index = last_index = last_index + 1
            else:
                current_index += 1
        return parts
