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

class Solution {
  public:
    bool wordPattern(string pattern, string str) {
      int i = 0;
      int word_start = 0;
      vector<string> toks;
      while (i < str.size()) {
        if (i == str.size() - 1) {
          toks.push_back(str.substr(word_start));
        }
        else if (str[i] == ' ') {
          toks.push_back(str.substr(word_start, i - word_start));
          word_start = i + 1;
        }
        i++;
      }
      unordered_map<char, string> dic;
      unordered_map<string, char> dic1;
      for (i = 0; i < pattern.size() && i < toks.size(); i++) {

        if (dic.count(pattern[i]) && dic[pattern[i]] != toks[i]) {
          return false;
        }
        else if (dic1.count(toks[i]) && dic1[toks[i]] != pattern[i]) {
          return false;
        }
        else {
          dic[pattern[i]] = toks[i];
          dic1[toks[i]] = pattern[i];
        }
      }
      if (i < pattern.size() || i < toks.size()) return false;
      return true;
    }
};




int main() {
  Solution s;
  cout << s.wordPattern("aaa", "aa aa aa aa");
  return 0;
}



