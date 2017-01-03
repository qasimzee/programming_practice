//https://leetcode.com/problems/ransom-note/
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
      map<char, int> mp_magazine;
      for (int i = 0; i < magazine.size(); i++) {
        if (mp_magazine.count(magazine[i]) == 0)
          mp_magazine[magazine[i]] = 1;
        else
          mp_magazine[magazine[i]]++;
      }
      for (int i = 0; i < ransomNote.size(); i++) {
        if (mp_magazine.count(ransomNote[i]) == 0 || mp_magazine[ransomNote[i]] == 0)
          return false;
        mp_magazine[ransomNote[i]]--;
      }
      return true;
    }
};
