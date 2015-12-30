//https://leetcode.com/problems/excel-sheet-column-number/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int titleToNumber(string s) {
      int n = s.size();
      int ans = 0;
      reverse(s.begin(), s.end());
      for (int i = 0; i < n; i++) {
        int power = pow(26, i);
        ans += (s[i] - 'A' + 1) * power;
      }
      return ans;
    }
};

int main() {
  Solution s;
  cout << s.titleToNumber("A");
  return 0;
}



