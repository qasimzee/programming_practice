//https://leetcode.com/problems/first-bad-version/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


bool isBadVersion(int version) {
  return version >= 5;
}

class Solution {
  public:
    int firstBadVersion(int n) {
      long long m = n/2;
      long long s = 1;
      long long e = n;
      long long bad = -1;

      while (s <= e) {
        if (isBadVersion(m)) {
          bad = m;
          e = m - 1;
        }
        else {
          s = m + 1;
        }
        m = (s + e) / 2;
      }
      return bad;
    }
};

int main() {
  Solution s;

  cout << s.firstBadVersion(50);
  return 0;
}



