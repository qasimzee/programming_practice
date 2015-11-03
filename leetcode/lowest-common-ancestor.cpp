//solution to https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == NULL) {
        return NULL;
      }
      if (root->val == p->val || root->val == q->val)
        return root;
      TreeNode *left = lowestCommonAncestor(root->left, p, q);
      TreeNode *right = lowestCommonAncestor(root->right, p, q);
      if (left && right)
        return root;
      if (left != NULL)
        return left;
      return right;
    }
};

int main() {
  Solution s;
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  TreeNode *p  = new TreeNode(2);
  TreeNode *q  = new TreeNode(8);
  TreeNode *t = s.lowestCommonAncestor(root, p, q);
  cout << t->val;
  return 0;
}



