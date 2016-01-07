//https://leetcode.com/problems/symmetric-tree/
class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
      if (root == NULL)
        return NULL;
      TreeNode *inverted_tree = new TreeNode(root->val);
      inverted_tree->left = invertTree(root->right);
      inverted_tree->right = invertTree(root->left);
      return inverted_tree;
    }
    bool isSame(TreeNode *tree1, TreeNode *tree2) {
      if (tree1 == NULL && tree2 == NULL)
        return true;
      if (tree1 != NULL && tree2 != NULL) {
        if (tree1->val == tree2->val) {
          bool is_same = isSame(tree1->left, tree2->left);
          if (is_same)
            return isSame(tree1->right, tree2->right);
          else
            return false;
        }
      }
      return false;
    }
    bool isSymmetric(TreeNode* root) {
      if (root == NULL)
        return true;
      TreeNode *inverted = invertTree(root);
      return isSame(root, inverted);
    }
};
