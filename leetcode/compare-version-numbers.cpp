//https://leetcode.com/problems/compare-version-numbers/
class Solution {
  public:
    int compareVersion(string version1, string version2) {

      vector<int> v1, v2;
      int x;
      for (int i = 0; i < version1.size(); i++)
        if (version1[i] == '.') version1[i] = ' ';

      for (int i = 0; i < version2.size(); i++)
        if (version2[i] == '.') version2[i] = ' ';

      stringstream ss1(version1), ss2(version2);
      while (ss1 >> x) {
        v1.push_back(x);
      }
      while (ss2 >> x) {
        v2.push_back(x);
      }
      while (v1.size() > 0 && v1[v1.size() - 1] == 0 ) {
        if (v1[v1.size() - 1] == 0)
          v1.erase(v1.end() - 1);
      }
      while (v2.size() > 0 && v2[v2.size() - 1] == 0) {
        if (v2[v2.size() - 1] == 0)
          v2.erase(v2.end() - 1);
      }
      int i = 0, j = 0;
      for (; i < v1.size() && j < v2.size(); i++, j++) {
        if (v1[i] > v2[i])
          return 1;
        if (v2[i] > v1[i])
          return -1;
      }
      if (i < v1.size())
        return 1;
      if (j < v2.size())
        return -1;
      return 0;
    }
};
