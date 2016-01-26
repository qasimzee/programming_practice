//https://leetcode.com/problems/palindrome-number/
class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0)
        return false;
      int a = x;
      int n = 0;
      int count = 1;
      while (a > 0) {
        n *=  10;
        n += (a % 10);
        a /= 10;
        count ++;
      }

      return x == n;
    }
};
