//Solution to https://leetcode.com/problems/path-sum/
class Solution {
  public:
    bool hasPathSum(TreeNode* root, int sum) {
      if (root == NULL)
        return false;
      if (root->left == NULL && root->right == NULL)
        return sum - root->val == 0;

      sum -= root-> val;
      if (hasPathSum(root->left, sum))
        return true;
      if (hasPathSum(root->right, sum))
        return true;
      return false;
    }
};
