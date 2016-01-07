//https://leetcode.com/problems/implement-queue-using-stacks/
class Queue {
  stack<int> stk1, stk2;
  public:

  void push(int x) {
    stk1.push(x);
  }


  void pop(void) {
    while (!stk1.empty()) {
      stk2.push(stk1.top());
      stk1.pop();
    }
    stk2.pop();
    while (!stk2.empty()) {
      stk1.push(stk2.top());
      stk2.pop();
    }
  }


  int peek(void) {
    while (!stk1.empty()) {
      stk2.push(stk1.top());
      stk1.pop();
    }
    int val = stk2.top();
    while (!stk2.empty()) {
      stk1.push(stk2.top());
      stk2.pop();
    }
    return val;
  }


  bool empty(void) {
    return stk1.empty();
  }
};
