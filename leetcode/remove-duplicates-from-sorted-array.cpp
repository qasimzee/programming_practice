//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() == 0)
        return 0;
      int j = 1;
      int i = 0;
      while (i < nums.size() && j < nums.size()) {
        while (j < nums.size() && nums[i] == nums[j]) {
          nums.erase(nums.begin() + j);
        }
        i++;
        if (i == j)
          j++;
      }
      return nums.size();
    }
};

