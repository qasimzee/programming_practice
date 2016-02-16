//https://leetcode.com/problems/summary-ranges/
class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> ret;
      if (nums.size() == 0)
        return ret;
      int start = nums[0];
      int count = 0;
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - nums[i - 1]  == 1) {
          count++;
        }
        else {
          stringstream ss;
          if (count > 0) {
            ss << start << "->" << nums[i - 1];
          }
          else {
            ss << start;
          }
          count = 0;
          start = nums[i];
          ret.push_back(ss.str());
        }
      }
      stringstream ss;
      if (count == 0) {
        ss << start;
        ret.push_back(ss.str());
      }
      if (count > 0) {
        ss << start << "->" << nums[nums.size() - 1];
        ret.push_back(ss.str());
      }

      return ret;
    }
};
