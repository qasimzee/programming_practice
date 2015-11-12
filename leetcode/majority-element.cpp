//Solution to: https://leetcode.com/problems/majority-element/
class Solution {
  public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int, int> map;
      for (int i = 0; i < nums.size(); i++) {
        map[nums[i]] ++;
        if (map[nums[i]] > floor(nums.size() / 2)) return nums[i];
      }
      return -1;
    }
};
