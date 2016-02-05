//https://leetcode.com/problems/add-binary/
class Solution {
  public:
    string addBinary(string a, string b) {
      int max_size = max(a.size(), b.size());
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      string ret = "";
      int carry = 0;
      for (int i = 0; i < max_size; i++) {
        int ans = 0;
        ans += (i < a.size()) ? a[i] - '0' : 0;
        ans += (i < b.size()) ? b[i] - '0' : 0;
        ans += carry;
        carry = ans > 1;
        if (ans == 2 || ans == 0) {
          ret = ret + "0";
        }
        else {
          ret += "1";
        }
      }
      if (carry) {
        ret += "1";
      }
      reverse(ret.begin(), ret.end());
      return ret;
    }
};
