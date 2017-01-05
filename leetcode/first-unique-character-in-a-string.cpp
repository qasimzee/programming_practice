//https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
  public:
    int firstUniqChar(string s) {
      map<char, pair<int, int>> mp;   //index: [a-z], val: (count, index)
      for (int i = 0; i < s.size(); i++) {
        if (mp.count(s[i]) == 0) {
          pair<int, int> p(1, i);
          mp[s[i]] = p;
        }
        else {
          mp[s[i]].first++;
        }
      }
      int ret = INT_MAX;

      for (auto it = mp.begin(); it != mp.end(); it++) {
        pair<int, int> p = it->second;
        if (p.first == 1 && p.second < ret) {
          ret = p.second;
        }
      }
      return ret == INT_MAX ? -1 : ret;
    }
};
