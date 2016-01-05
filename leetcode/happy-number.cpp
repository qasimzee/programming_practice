//https://leetcode.com/problems/happy-number/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
  public:
    int getSum(int x) {
      int sum = 0;
      while (x != 0) {
        sum += ((x % 10) * (x % 10));
        x /= 10;
      }
      return sum;
    }
    bool isHappy(int n) {
      unordered_map<int, bool> map;
      map[n] = true;
      while (n != 1) {
        n = getSum(n);
        if (map[n]) {
          return false;
        }
        map[n] = true;
      }
      return true;
    }
};

int main() {
  Solution s;
  cout << s.isHappy(7);
  return 0;
}


