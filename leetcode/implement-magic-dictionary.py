#https://leetcode.com/problems/implement-magic-dictionary/description/
class MagicDictionary(object):
    
    def __init__(self):
        """
            Initialize your data structure here.
            """
    
    
    def buildDict(self, dict):
        self.words = []
        for word in dict:
            for i in range(len(word)):
                temp = list(word)
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    if (word[i] != ch):
                        temp[i] = ch
                        self.words.append("".join(temp))

def search(self, word):
    self.words.sort()
        for x in self.words:
            if (x == word):
                return True
    return False



# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
