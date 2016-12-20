//https://leetcode.com/problems/hamming-distance/
class Solution {
  public:
    int hammingDistance(int x, int y) {
      bitset<32> b(x ^ y);
      return b.count();
    }
};
