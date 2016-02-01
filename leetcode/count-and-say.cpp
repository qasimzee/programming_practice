//https://leetcode.com/problems/count-and-say/
class Solution {
  public:
    string countAndSay(int n) {
      string start = "1";
      for (int i = 1; i < n; i++) {
        stringstream ss;
        for (int j = 0; j < start.size(); j++) {
          char ch = start[j];
          int count = 0;
          while (j < start.size() && start[j] == ch) {
            count++;
            j++;
          }
          ss << count << ch;
          j--;
        }
        start = ss.str();
      }
      return start;
    }
};

