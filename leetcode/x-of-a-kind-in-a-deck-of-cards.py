# https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
from collections import Counter
class Solution:
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        deck_map = Counter(deck)
        min_element = deck_map.most_common()[-1][1]
        for i in range(2, min_element + 1):
            found_divisor = True
            for key, val in deck_map.items():
                if val % i != 0:
                    found_divisor = False
            if found_divisor:
                return True
        return False
