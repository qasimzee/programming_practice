//https://leetcode.com/problems/bulls-and-cows/
class Solution {
  public:
    string getHint(string secret, string guess) {
      unordered_map<char, int> map1, map2;
      int cows = 0, bulls = 0;
      for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) {
          bulls++;
        }
        else {
          if (map2.count(secret[i]) && map2[secret[i]] > 0) {
            map2[secret[i]]--;
            cows++;
          }
          else {
            map1[secret[i]]++;
          }
          if (map1.count(guess[i]) && map1[guess[i]] > 0) {
            map1[guess[i]]--;
            cows++;
          }
          else {
            map2[guess[i]]++;
          }
        }
      }
      stringstream ss;
      ss << bulls << "A" << cows << "B";
      return ss.str();
    }
};
