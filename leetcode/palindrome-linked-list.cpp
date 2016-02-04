//Solution to https://leetcode.com/problems/palindrome-linked-list/
class Solution {
  public:
    bool isPalindrome(ListNode* head) {
      int n = 0;
      if (head == NULL) return true;
      ListNode *node = head;
      while (node != NULL) {
        n++;
        node = node->next;
      }
      stack<ListNode*> stk;
      node = head;
      int i = 0;
      while (i < n/2) {
        stk.push(node);
        node = node->next;
        i++;
      }
      if (n % 2 == 1)
        node = node->next;
      while (node != NULL) {
        ListNode *p_node = stk.top();
        stk.pop();
        if (p_node->val != node->val)
          return false;
        node = node->next;
      }
      return true;
    }
};
