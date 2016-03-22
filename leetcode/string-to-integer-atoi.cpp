//https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
  public:
    int myAtoi(string str) {
      int i = 0;
      bool sign = false;
      int ret = 0;
      while (str[i] == ' ') {
        i++;
      }
      if (str[i] == '-') {
        sign = true;
        i++;
      }
      else if (str[i] == '+') {
        sign = false;
        i++;
      }
      long long prev_ret = 0;
      while (i < str.size() && str[i] <= '9' && str[i] >= '0') {

        ret *= 10;
        ret += (str[i] - '0');
        prev_ret *= 10;
        prev_ret += (str[i] - '0');
        if (ret != prev_ret) {
          if (sign) return INT_MIN;
          return INT_MAX;
        }
        i++;
      }
      if (sign)
        ret *= -1;
      return ret;
    }
};
