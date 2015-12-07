//https://leetcode.com/problems/reverse-linked-list/
#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      if (head == NULL)
        return head;
      stack<ListNode*> stk;
      ListNode *node = head;
      while (node != NULL) {
        stk.push(node);
        node = node->next;
      }
      node = head = stk.top();
      stk.pop();
      while (!stk.empty()) {
        ListNode *tempnode = stk.top();
        node->next = tempnode;
        node = tempnode;
        stk.pop();
      }
      node->next = NULL;
      return head;
    }
};

int main() {
  ListNode *root = new ListNode(1);
  root->next = new ListNode(2);
  root->next->next = new ListNode(3);
  root->next->next->next = new ListNode(4);
  Solution *s=new Solution();
  root = s->reverseList(root);
  ListNode *node = root;
  while (node != NULL) {
    cout << node->val;
    node = node->next;
  }
  return 0;
}


