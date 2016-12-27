//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++) {
        int val = abs(nums[i]) - 1;
        if (nums[val] > 0) {
          nums[val] = -nums[val];
        }
      }
      vector<int> v;
      for (int i = 1; i <= nums.size(); i++) {
        if (nums[i - 1] > 0) v.push_back(i);
      }
      return v;
    }
};
