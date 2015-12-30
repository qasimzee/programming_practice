//Solution to https://leetcode.com/problems/climbing-stairs/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int climbStairs(int n) {
      int n1 = 1, n2 = 2;
      if (n <= 2)
        return n;

      for (int i = 3; i <= n; i++) {
        int val = n1 + n2;
        n1 = n2;
        n2 = val;
      }
      return n2;
    }
};
