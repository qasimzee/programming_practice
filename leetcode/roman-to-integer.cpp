//https://leetcode.com/problems/roman-to-integer/
class Solution {
  public:

    int romanToInt(string s) {
      int ret = 0;
      map<char, int> vals;
      vals['I'] = 1;
      vals['V'] = 5;
      vals['X'] = 10;
      vals['L'] = 50;
      vals['C'] = 100;
      vals['D'] = 500;
      vals['M'] = 1000;
      int ans = 0;
      for (int i = 0; i < s.size(); i++) {
        if (i == 0)
          ans += vals[s[i]];
        if (i > 0) {
          if (vals[s[i]] > vals[s[i-1]]) {
            ans -= 2 * vals[s[i-1]];
          }
          ans += vals[s[i]];

        }
      }
      return ans;
    }
};
