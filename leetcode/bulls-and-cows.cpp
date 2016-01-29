//https://leetcode.com/problems/bulls-and-cows/
class Solution {
  public:
    string getHint(string secret, string guess) {
      unordered_map<char, int> map1;
      int cows = 0, bulls = 0;
      for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) {
          bulls++;
          guess[i] = ' ';
        }
        else {
          map1[secret[i]]++;
        }
      }
      for (int i = 0; i < guess.size(); i++) {
        if (map1.count(guess[i]) && map1[guess[i]] > 0) {
          cows++;
          map1[guess[i]]--;
        }
      }
      stringstream ss;
      ss << bulls << "A" << cows << "B";
      return ss.str();
    }
};
