struct TreeNodeM{
  TreeNode *node;
  string path;
  TreeNodeM(TreeNode *n, string p)  {
    node = n;
    path = p;
  }
};

class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> ret;
      if (root == NULL) return ret;
      TreeNodeM *node = new TreeNodeM(root, to_string(root->val));


      queue<TreeNodeM*> q;
      q.push(node);
      while (!q.empty()) {
        TreeNodeM *n = q.front();
        q.pop();
        if (n->node->left == NULL && n->node->right == NULL) {
          ret.push_back(n->path);
        }
        if (n->node->left != NULL) {
          TreeNodeM *left = new TreeNodeM(n->node->left, n->path + "->" + to_string(n->node->left->val));
          q.push(left);
        }
        if (n->node->right != NULL) {
          TreeNodeM *right = new TreeNodeM(n->node->right, n->path + "->" + to_string(n->node->right->val));
          q.push(right);
        }
      }
      return ret;
    }
};
