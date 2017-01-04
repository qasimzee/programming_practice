//https://leetcode.com/problems/sum-of-left-leaves/

class Solution {
  public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
      if (root == NULL) return 0;
      if (root->left == NULL && root ->right == NULL) return isLeft ? root->val : 0;
      return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
