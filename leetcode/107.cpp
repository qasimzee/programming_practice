#include <cmath>
#include <fstream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeWithLevel {
  TreeNode *node;
  int level;
};

class Solution {
  public:

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> ret;
      if (root == NULL)
        return ret;
      queue<TreeNodeWithLevel> q;
      int level = 0;
      q.push({root, level});
      while (!q.empty()) {
        TreeNodeWithLevel node = q.front();
        q.pop();
        if (node.node->left != NULL) {
          q.push({node.node->left, node.level + 1});
        }
        if (node.node->right != NULL) {
          q.push({node.node->right, node.level + 1});
        }
        if (ret.size() <= node.level) {
          vector<int> v;
          v.push_back(node.node->val);
          ret.push_back(v);
        }
        else {
          ret[node.level].push_back(node.node->val);
        }
      }
      reverse(ret.begin(), ret.end());
      return ret;
    }
};
int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  Solution s;
  s.levelOrderBottom(root);
  return 0;
}


