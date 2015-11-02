//https://leetcode.com/problems/number-of-1-bits/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int hammingWeight(uint32_t n) {
      int ones = 0;
      while (n > 0) {
        ones += n % 2;
        n /= 2;
      }
      return ones;
    }
};

int main() {
  Solution s;
  cout << s.hammingWeight(123);
  return 0;
}



