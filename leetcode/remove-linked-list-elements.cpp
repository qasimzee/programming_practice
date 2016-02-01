//https://leetcode.com/problems/remove-linked-list-elements/
class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      if (head == NULL)
        return head;
      while (head != NULL && head->val == val) {
        head = head->next;
      }
      if (head == NULL)
        return NULL;
      ListNode * node = head;
      while (node != NULL) {
        while (node->next != NULL && node->next->val == val) {
          node->next = node->next->next;
        }
        node = node->next;
      }
      return head;
    }
};

