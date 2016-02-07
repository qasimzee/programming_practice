//Solution to https://leetcode.com/problems/implement-strstr/
class Solution {
  public:
    int strStr(string haystack, string needle) {
      if (needle.size() == 0)
        return 0;
      if (needle.size() > haystack.size())
        return -1;
      for (int i = 0; i <= haystack.size() - needle.size(); i++) {
        if (haystack[i] == needle[0]) {
          int j = i;
          int k = 0;
          while (j < haystack.size() && k < needle.size() && needle[k] == haystack[j]) {
            j++;
            k++;
          }
          if (k == needle.size())
            return i;
        }
      }
      return -1;
    }

};
