//https://leetcode.com/problems/longest-palindrome/
class Solution {
  public:
    int longestPalindrome(string s) {
      map<char, int> mp;
      for (int i = 0; i < s.size(); i++) {
        if (mp.count(s[i]) == 0) {
          mp[s[i]] = 0;
        }
        mp[s[i]]++;
      }
      int count = 0;
      for (auto it = mp.begin(); it != mp.end(); it ++) {
        count += it->second - it->second % 2;
      }
      return count < s.size() ? count + 1 : count;
    }
};
