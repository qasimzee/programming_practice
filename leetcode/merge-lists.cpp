//https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *result = NULL, *temp = NULL;
      while (l1 != NULL && l2 != NULL) {
        ListNode *val;
        if (l1->val < l2->val) {
          val = l1;
          l1 = l1->next;
        }
        else {
          val = l2;
          l2 = l2->next;
        }
        if (result == NULL) {
          temp = result = val;
        }
        else {
          temp->next = val;
          temp = temp->next;
        }
      }
      if (l1 != NULL) {
        if (result != NULL)
          temp->next = l1;
        else 
          result = l1;
      }
      if (l2 != NULL) {
        if (result != NULL)
          temp->next = l2;
        else 
          result = l2;
      }
      return result;
    }
};
