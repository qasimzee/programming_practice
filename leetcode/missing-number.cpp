//https://leetcode.com/problems/missing-number/
class Solution {
  public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      long long sum = 0;
      for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
      }
      return n*(n + 1)/2 - sum;
    }
};
