//https://leetcode.com/problems/single-number-iii/
class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
      unordered_map<int, int> map;
      vector<int> ret;
      for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
      }
      for (auto it = map.begin(); it != map.end(); it++) {
        if (it->second == 1)
        {
          ret.push_back(it->first);
        }
      }
      return ret;
    }

};
