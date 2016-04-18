//Solution to https://leetcode.com/problems/product-of-array-except-self/
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> res;
      for (int i = 0; i < nums.size() ; i++) {
        res.push_back(1);
      }

      for (int i = nums.size() - 2; i >=0; i--) {
        res[i] = res[i+1] * nums[i+1];
      }
      int left = 1;
      for(int i = 0; i < nums.size(); i++) {
        res[i] *= left;
        left *= nums[i];
      }
      return res;
    }
};
