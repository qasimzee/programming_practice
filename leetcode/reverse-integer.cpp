//Solution to https://leetcode.com/problems/reverse-integer/
class Solution {
  public:
    int reverse(int x) {
      long long reverse = 0;
      int n = x;
      if (x < 0)
        n *= -1;
      while (n != 0)  {
        reverse *= 10;
        reverse += n % 10;
        n /= 10;
      }
      int k = (int) reverse;
      if (k != reverse)
        return 0;
      if (x < 0)
        k *= -1;
      return k;
    }
};
