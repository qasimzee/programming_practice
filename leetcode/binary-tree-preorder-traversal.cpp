//https://leetcode.com/problems/binary-tree-preorder-traversal/
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
      vector<int> v;
      if (root == NULL)
        return v;
      stack<TreeNode*> stk;
      stk.push(root);
      while (!stk.empty()) 
      {
        TreeNode *node = stk.top();
        stk.pop();
        v.push_back(node->val);

        if (node->right != NULL)
          stk.push(node->right);
        if (node->left != NULL)
          stk.push(node->left);
      }
      return v;
    }
};
