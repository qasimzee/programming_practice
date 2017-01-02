//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
class Solution {
  public:

    int minMoves(vector<int>& nums) {
      int moves = 0;

      int min_elem = *std::min_element(nums.begin(), nums.end());

      for (int i = 0; i < nums.size(); i++) {
        moves += nums[i] - min_elem;
      }

      return moves;
    }
};
