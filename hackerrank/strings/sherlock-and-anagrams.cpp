//Solution to https://www.hackerrank.com/challenges/sherlock-and-anagrams

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.length();
    map <string, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        string w = s.substr(i, j - i + 1);
        sort(w.begin(), w.end());
        ans += mp[w];
        ++mp[w];
      }
    }
    cout << ans << endl;
  }
  return 0;
}



