//https://leetcode.com/problems/balanced-binary-tree/
class Solution {
  public:
    int getHeight(TreeNode* root) {
      if (root == NULL)
        return 0;
      return max(1 + getHeight(root->left), 1 + getHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
      if (root == NULL) return true;
      int h1 = getHeight(root->left);
      int h2 = getHeight(root->right);

      if (abs(h1 - h2) <= 1) {
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        return left && right;
      }
      return false;
    }
};
