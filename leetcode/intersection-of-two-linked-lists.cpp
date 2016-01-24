#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *node = headA;
      int size1 = 0, size2 = 0;
      while (node != NULL) {
        size1++;
        node = node->next;
      }
      node = headB;
      while (node != NULL) {
        size2++;
        node = node->next;
      }
      ListNode *node1 = NULL;
      if (size1 > size2) {
        int diff = size1 - size2;
        node = headA;
        while (diff--) {
          node = node->next;
        }
        node1 = headB;
      }
      else {
        int diff = size2 - size1;
        node = headB;
        while (diff--) {
          node = node->next;
        }
        node1 = headA;
      }
      while (node != NULL && node1 != NULL) {
        if (node == node1)
          return node;
        node = node->next;
        node1 = node1->next;
      }
      return NULL;
    }
};
int main()
{
  ListNode *head1 = new ListNode(1), *head2 = new ListNode(2);
  head1->next = new ListNode(3);
  head2->next = new ListNode(4);
  head2->next->next = new ListNode(5);
  head2->next->next->next = new ListNode(6);
  head1->next = head2->next->next;
  Solution s;
  ListNode *inter = s.getIntersectionNode(head1, head2);
  cout << inter->val;
  return 0;
}
