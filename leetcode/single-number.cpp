//https://leetcode.com/problems/single-number/
class Solution {
  public:
    int singleNumber(vector<int>& nums) {
      unordered_map<int, int> map;
      for (int i = 0; i < nums.size(); i++) {
        if (map.count(nums[i])) {
          map[nums[i]]++;
        }
        else {
          map[nums[i]] = 1;
        }

      }
      for (auto it = map.begin(); it != map.end(); it++) {
        if (it->second == 1)
          return it->first;
      }
      return 0;
    }
};
