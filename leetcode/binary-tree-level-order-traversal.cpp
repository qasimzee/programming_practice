//Solution to https://leetcode.com/problems/binary-tree-level-order-traversal/
struct TreeNodeLevel {
  TreeNode *treeNode;
  int level;
  TreeNodeLevel(TreeNode *t, int l) : level(l), treeNode(t) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ret;
      if (root == NULL)
        return ret;
      queue<TreeNodeLevel*> q;
      q.push(new TreeNodeLevel(root, 1));
      while (!q.empty()) {
        TreeNodeLevel *node = q.front();
        q.pop();
        if (node->level > ret.size()) {
          vector<int> v;
          v.push_back(node->treeNode->val);
          ret.push_back(v);
        }
        else {
          ret[node->level - 1].push_back(node->treeNode->val);
        }
        if (node->treeNode->left != NULL) 
          q.push(new TreeNodeLevel(node->treeNode->left, node->level + 1));
        if (node->treeNode->right != NULL) 
          q.push(new TreeNodeLevel(node->treeNode->right, node->level + 1));
      }
      return ret;
    }
};
