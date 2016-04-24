//https://leetcode.com/problems/integer-break/
class Solution {
  public:
    int integerBreak(int n) {
      if (n == 2) return 1;
      if (n == 3) return 2;
      if (n == 4) return 4;
      long long prod = 1;
      for (; n > 2; n-=3) {
        prod *= 3;
      }
      if (n == 1) {
        prod /= 3;
        prod *= 4;
      }
      else if (n == 2) {
        prod *= 2;
      }
      return prod;
    }
};
