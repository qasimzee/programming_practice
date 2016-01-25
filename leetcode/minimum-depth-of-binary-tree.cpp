//https://leetcode.com/problems/minimum-depth-of-binary-tree/
#include<iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
  public:

    int minDepth(TreeNode* root) {
      if (root == NULL)
        return 0;
      if (root->left == NULL && root->right == NULL)
        return 1;
      int depth = 0;
      int depth_left = 1 + minDepth(root->left);
      int depth_right = 1 + minDepth(root->right);
      if (depth_left > 1 && depth_right > 1) {
        depth = min(depth_left, depth_right);
      }
      else if (depth_right > 1) {
        depth = depth_right;
      }
      else {
        depth = depth_left;
      }
      return depth;
    }
};

int main()
{
  TreeNode *t = new TreeNode(1);
  Solution s;
  cout << s.minDepth(t) << endl;
  t -> left = new TreeNode(2);
  cout << s.minDepth(t) << endl;
  t -> left->left = new TreeNode(4);
  cout << s.minDepth(t) << endl;
  t -> left->left->left = new TreeNode(5);
  cout << s.minDepth(t) << endl;
  return 0;
}
