//https://leetcode.com/problems/counting-bits/
class Solution {
  public:
    int countBBits(int n) {
      int ans = 0;
      while (n > 0) {
        ans += n % 2;
        n /= 2;
      }
      return ans;
    }
    vector<int> countBits(int num) {
      vector<int> ret;
      for (int i = 0; i <= num; i++) {
        ret.push_back(countBBits(i));
      }
      return ret;
    }
};
