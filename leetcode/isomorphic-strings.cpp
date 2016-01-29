//https://leetcode.com/problems/isomorphic-strings/
class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      if (s.size() != t.size())
        return false;
      unordered_map<char, char> map1;
      unordered_map<char, char> map2;
      for (int i = 0; i < s.size(); i++) {
        if (map1.count(s[i])) {
          if (t[i] != map1[s[i]])
            return false;
        }
        else {
          map1[s[i]] = t[i];
        }
        if (map2.count(t[i])) {
          if (s[i] != map2[t[i]])
            return false;
        }
        else {
          map2[t[i]] = s[i];
        }
      }
      return true;
    }
};

