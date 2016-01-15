//https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
  public:
    int trailingZeroes(int n) {
      long long x = 5;
      int ans = 0;
      while (n / x > 0) {
        ans += n / x;
        x *= 5;
      }
      return ans;
    }
};
