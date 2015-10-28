//solution to https://leetcode.com/problems/same-tree/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
      if (p != NULL && q != NULL && p->val == q->val)
      {
        bool left_same = isSameTree(p->left, q->left);
        if (left_same) return isSameTree(p->right, q->right);
      }
      else if (p == NULL && q == NULL)
      {
        return true;
      }
      return false;
    }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  TreeNode* root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);
  root1->right->left = new TreeNode(6);
  root1->right->right = new TreeNode(7);

  Solution *s = new Solution();
  cout << s -> isSameTree(root, root1);
  return 0;
}


