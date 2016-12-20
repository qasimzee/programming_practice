//https://leetcode.com/problems/find-the-difference/
class Solution {
  public:
    char findTheDifference(string s, string t) {
      sort(s.begin(), s.end());
      sort(t.begin(), t.end());
      int i;
      for ( i = 0; i < s.size() && i < t.size(); i++) {
        if (s[i] != t[i])
        {
          if (i < s.size() - 1 && s[i + 1] == t[i])
            return s[i];
          return t[i];
        }
      }
      return i < t.size() ? t[i] : s[i];
    }
};
