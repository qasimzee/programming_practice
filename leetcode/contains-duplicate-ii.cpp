//https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> map;
      if (k == 0)
        return false;
      for (int i = 0; i < nums.size(); i++) {
        if (map.count(nums[i])) {
          if (abs(map[nums[i]] - i) <= k) {
            return true;
          }
        }
        map[nums[i]] = i;
      }
      return false;
    }
};
