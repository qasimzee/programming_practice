class Solution {
  public:
    vector<int> countBits(int num) {
      vector<int> ret;
      if (num == 0) {
        ret.push_back(0);
        return ret;
      }
      ret.push_back(0);
      if (num == 1) {
        ret.push_back(1);
        return ret;
      }
      ret.push_back(1);
      if (num == 2) {
        ret.push_back(1);
        return ret;
      }
      ret.push_back(1);
      for (int i = 3; i <= num; i++) {

      }
    }
};
