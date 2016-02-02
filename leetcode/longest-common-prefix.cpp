//https://leetcode.com/problems/longest-common-prefix/
class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() == 0)
        return "";
      int min_size = INT_MAX;
      for (int i = 0; i < strs.size(); i++) {
        if (strs[i].size() < min_size) {
          min_size = strs[i].size();
        }
      }
      string pref = "";
      for (int i = 0; i < min_size; i++) {
        char ch = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
          if (strs[j][i] != ch) {
            return pref;
          }
        }
        pref += ch;
      }
      return pref;
    }
};
