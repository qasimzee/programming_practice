//Solution to: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#include <cmath>
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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* current = head;
      if (current == NULL || current -> next == NULL)
        return head;
      while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
          ListNode *temp = current->next;
          while(temp != NULL && temp->val == current->val) {
            temp = temp->next;
          }
          current->next = temp;
        }
        current = current->next;
      }
      return head;
    }
};

int main() {
  Solution s;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(3);
  head->next->next->next->next->next = new ListNode(3);

  head = s.deleteDuplicates(head);
  while (head != NULL) {
    cout << head->val << endl;
    head = head->next;
  }
  return 0;
}


