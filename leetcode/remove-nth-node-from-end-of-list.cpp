//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *current = head;
      int count = 0;
      ListNode *to_remove = NULL;
      while (current != NULL) {
        current = current->next;
        if (count >= n) {
          if (to_remove == NULL)
            to_remove = head;
          else
            to_remove = to_remove->next;
        }
        count ++;
      }
      if (n <= count) {
        if (to_remove == NULL)
          head = head->next;
        else if (to_remove->next == NULL)
          to_remove = NULL;
        else {
          to_remove->next = to_remove->next->next;
        }
      }
      return head;
    }
};
