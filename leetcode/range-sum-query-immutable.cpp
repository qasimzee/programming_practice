//https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
  vector<int> sums;
  public:
  NumArray(vector<int> &nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      sums.push_back(sum);
    }
  }

  int sumRange(int i, int j) {
    if (i == 0) {
      return sums[j];
    }
    return sums[j] - sums[i - 1];
  }
};
