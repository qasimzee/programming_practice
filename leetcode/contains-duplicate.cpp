//Solution to https://leetcode.com/problems/contains-duplicate/
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int, int> map;
      for (int i = 0; i < nums.size(); i++)
      {
        if (map.count(nums[i])) return true;
        map[nums[i]] = 1;
      }
      return false;
    }
};
